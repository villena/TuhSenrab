#include <iostream>
#include <cassert>
#include <math.h>
#include "coordenada.h"
#include "cuerpo.h"
#include "bhnode.h"

const double kTHETA=0.5;
const double kG=6.67428*pow(10, -11);

using namespace std;

// --------------------------------------------------- //

BHNode::BHNode(){
	masa=0.0;
	centroMasa=Coordenada();
	esqSupIzq=Coordenada();
	esqInfDer=Coordenada();
	centroCuadrante=Coordenada();
	lado=0.0;
	numCuerpos=0;
	nodoPadre=NULL;
	cuerpoInterior=NULL;

	for(int i=0; i<4; i++)
		hijosCuadrante[i]=NULL;
}

// --------------------------------------------------- //

BHNode::BHNode(Coordenada supIzq, Coordenada infDer, BHNode *padre){
	masa=0.0;
	centroMasa=Coordenada();
	esqSupIzq=supIzq;
	esqInfDer=infDer;
	this->calculaCentro(centroCuadrante);
	lado=fabs(esqInfDer.getX()-esqSupIzq.getX());
	numCuerpos=0;
	nodoPadre=padre;
	cuerpoInterior=NULL;

	for(int i=0; i<4; i++)
		hijosCuadrante[i]=NULL;
}

// --------------------------------------------------- //

BHNode::~BHNode(){
	masa=0.0;
	centroMasa.~Coordenada();
	esqSupIzq.~Coordenada();
	esqInfDer.~Coordenada();
	centroCuadrante.~Coordenada();
	lado=0.0;
	numCuerpos=0;
	nodoPadre=NULL;
	cuerpoInterior=NULL;

	for(int i=0; i<4; i++){
		if(hijosCuadrante[i]!=NULL){
			hijosCuadrante[i]->~BHNode();
			delete hijosCuadrante[i];
			hijosCuadrante[i]=NULL;
		}
	}
}

// --------------------------------------------------- //

double BHNode::getMasa() const{
	return masa;
}

// --------------------------------------------------- //

Coordenada BHNode::getCentroMasa() const{
	return centroMasa;
}

// --------------------------------------------------- //

Coordenada BHNode::getSupIzq() const{
	return esqSupIzq;
}

// --------------------------------------------------- //

Coordenada BHNode::getInfDer() const{
	return esqInfDer;
}

// --------------------------------------------------- //

Coordenada BHNode::getCentroCuad() const{
	return centroCuadrante;
}

// --------------------------------------------------- //

float BHNode::getLado() const{
	return lado;
}

// --------------------------------------------------- //

unsigned int BHNode::getNumCuerpos() const{
	return numCuerpos;
}

// --------------------------------------------------- //

BHNode * BHNode::getPadre() const{
	return nodoPadre;
}

// --------------------------------------------------- //

bool BHNode::esRaiz() const{
	return nodoPadre==NULL;
}

// --------------------------------------------------- //

bool BHNode::esHoja() const{
	bool raiz=true;

	for(int i=0; i<4; i++){
		if(hijosCuadrante[i]!=NULL)
			raiz=false;
	}

	return raiz;
}

// --------------------------------------------------- //

bool BHNode::introducirCuerpo(Cuerpo &cuerpo){
	Coordenada coordCuerpo=cuerpo.getPosicion();

	if(!this->estaDentro(coordCuerpo)) //Debe estar dentro
		return false;

	if(numCuerpos==0){ //Primer cuerpo en este cuadrante.
		assert(this->esHoja()==true);

		numCuerpos++;
		cuerpoInterior=&cuerpo;

		return true;
	}
	else if(numCuerpos>1){ //Tiene más de un cuerpo, ya está expandido.
		assert(this->esHoja()==false);

		numCuerpos++;

		BHNode *cuadrante=this->obtenerCuadrante(coordCuerpo);
		return cuadrante->introducirCuerpo(cuerpo);
	}
	else{ //Tiene un cuerpo ya. Habrá que expandirlo.
		assert(this->esHoja()==true);

		BHNode *auxNode=NULL;
		Cuerpo *auxCuerpo=cuerpoInterior;
		cuerpoInterior=NULL;

		this->expandirNodo();

		//Realocamos el cuerpo que ya estaba aquí.
		auxNode=this->obtenerCuadrante(auxCuerpo->getPosicion());
		auxNode->introducirCuerpo(*auxCuerpo);

		numCuerpos++;
		auxNode=this->obtenerCuadrante(coordCuerpo);
		return auxNode->introducirCuerpo(cuerpo);
	}
}

// --------------------------------------------------- //

void BHNode::calcularDistribucionMasas(){
	if(numCuerpos==1){ //Solo un cuerpo.
		centroMasa=cuerpoInterior->getPosicion();
		masa=cuerpoInterior->getMasa();
	}
	else{ //0 o más de uno.
		float newX=centroMasa.getX(), newY=centroMasa.getY();
		//#pragma omp parallel for
		for(int i=0; i<4; i++){
			if(hijosCuadrante[i]){ //Si tuviese 0 hijos, no se ejecuta nada de esto.
				hijosCuadrante[i]->calcularDistribucionMasas();

				masa+=hijosCuadrante[i]->masa;
				newX+=hijosCuadrante[i]->centroMasa.getX()*hijosCuadrante[i]->masa;
				newY+=hijosCuadrante[i]->centroMasa.getY()*hijosCuadrante[i]->masa;
			}
		}

		centroMasa.setX(newX/masa);
		centroMasa.setY(newY/masa);
	}
}

// --------------------------------------------------- //

double BHNode::calculaFuerza(const Cuerpo &cuerpo){
	//Si es el mismo cuerpo, no se ejerce fuerza a sí mismo.
	//Si no tiene cuerpos, no afecta.
	if(cuerpoInterior==&cuerpo || numCuerpos==0) 
		return 0.0;

	double fuerza=0.0;
	double r=0.0;

	r=cuerpo.getPosicion().distanciaEuclidea(centroMasa);

	if(numCuerpos==1)
		fuerza=kG*cuerpo.getMasa()*masa/pow(r, 2);
	else{
		if(lado/r<kTHETA)
			fuerza = kG*cuerpo.getMasa()*masa/pow(r, 2);
		else{
			for(int i=0; i<4; i++){
				if(hijosCuadrante[i])
					fuerza+=hijosCuadrante[i]->calculaFuerza(cuerpo);
			}
		}
	}

	return fuerza;
}

// --------------------------------------------------- //

BHNode * BHNode::obtenerCuadrante(Coordenada coordCuerpo){
	assert(this->esHoja()==false); //Solo si ya está expandido podemos obtener cuadrantes.

	float compX=coordCuerpo.getX(), compY=coordCuerpo.getY();
	float xCentro=centroCuadrante.getX(), yCentro=centroCuadrante.getY();
	BHNode* aux=NULL;

	if(compX<=xCentro && compY<=yCentro) //Noroeste
		aux=hijosCuadrante[0];
	else if(compX>=xCentro && compY<=yCentro) //Noreste
		aux=hijosCuadrante[1];
	else if(compX<=xCentro && compY>=yCentro) //Suroeste
		aux=hijosCuadrante[2];
	else if(compX>=xCentro && compY>=yCentro) //Sureste
		aux=hijosCuadrante[3];
	else //No está en este cuadrante!!!
		aux=NULL;

	return aux;
}


// --------------------------------------------------- //


/*      X -> +
 * 	   _________
 * Y  |    |    |
 * 	  |__0_|_1__|  
 * +  |	   |    |
 * 	  |__2_|_3__|
 */

void BHNode::expandirNodo(){
	assert(this->esHoja()==true);

	Coordenada supIzq0(esqSupIzq);
	Coordenada infDer0(centroCuadrante);

	hijosCuadrante[0]=new BHNode(supIzq0, infDer0, this);

	Coordenada supIzq1(centroCuadrante.getX(), esqSupIzq.getY());
	Coordenada infDer1(esqInfDer.getX(), centroCuadrante.getY());

	hijosCuadrante[1]=new BHNode(supIzq1, infDer1, this);

	Coordenada supIzq2(esqSupIzq.getX(), centroCuadrante.getY());
	Coordenada infDer2(centroCuadrante.getX(), esqInfDer.getY());

	hijosCuadrante[2]=new BHNode(supIzq2, infDer2, this);

	Coordenada supIzq3(centroCuadrante);
	Coordenada infDer3(esqInfDer);

	hijosCuadrante[3]=new BHNode(supIzq3, infDer3, this);
}

// --------------------------------------------------- //

void BHNode::generaSVG(Lienzo &lienzo){
	if(this->esHoja()){
		lienzo.drawSquare(esqSupIzq, lado);

		if(cuerpoInterior)
			lienzo.drawCircle(cuerpoInterior->getPosicion(), cuerpoInterior->getMasa());
	}
	else{
		for(int i=0; i<4; i++){
			if(hijosCuadrante[i])
				hijosCuadrante[i]->generaSVG(lienzo);
		}
	}
}


// --------------------------------------------------- //

ostream & operator<<(ostream &op, const BHNode &node){
	op << "es raíz? " << node.esRaiz() << endl;
	op << "es hoja? " << node.esHoja() << endl;
	op << "cuerpos? " << node.getNumCuerpos() << endl;

	if(!node.esHoja()){
		op << "Hijo NO. Cuerpos: " << node.hijosCuadrante[0]->getNumCuerpos() << endl;
		op << "Hijo NE. Cuerpos: " << node.hijosCuadrante[1]->getNumCuerpos() << endl;
		op << "Hijo SO. Cuerpos: " << node.hijosCuadrante[2]->getNumCuerpos() << endl;
		op << "Hijo SE. Cuerpos: " << node.hijosCuadrante[3]->getNumCuerpos();
	}
	else
		op << "Sin hijos";

	return op;
}

// --------------------------------------------------- //
// --------------------------------------------------- //
// --------------------------------------------------- //

void BHNode::calculaCentro(Coordenada &coord){ 
	float compX, compY;

	compX=(esqInfDer.getX()-esqSupIzq.getX())/2+esqSupIzq.getX();
	compY=(esqInfDer.getY()-esqSupIzq.getY())/2+esqSupIzq.getY();

	coord=Coordenada(compX, compY);
}

// --------------------------------------------------- //

bool BHNode::estaDentro(Coordenada coord){
	bool contenido=false;
	float xCord=coord.getX(), yCord=coord.getY();
	
	if(xCord>=esqSupIzq.getX() && xCord<=esqInfDer.getX() &&
		yCord>=esqSupIzq.getY() && yCord<=esqInfDer.getY())
		contenido=true;

	return contenido;
}
