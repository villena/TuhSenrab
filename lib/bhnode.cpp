#include <iostream>
#include "coordenada.h"
#include "cuerpo.h"
#include "bhnode.h"

#include <cassert>

using namespace std;

// --------------------------------------------------- //

BHNode::BHNode(){
	masa=0.0;
	centroMasa=Coordenada();
	esqInfIzq=Coordenada();
	esqSupDer=Coordenada();
	centroCuadrante=Coordenada();
	numCuerpos=0;
	nodoPadre=NULL;
	cuerpoInterior=NULL;

	for(int i=0; i<4; i++)
		hijosCuadrante[i]=NULL;
}

// --------------------------------------------------- //

BHNode::BHNode(Coordenada infIzq, Coordenada supDer, BHNode *padre){
	masa=0.0;
	centroMasa=Coordenada();
	esqInfIzq=infIzq;
	esqSupDer=supDer;
	this->calculaCentro(centroCuadrante);
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
	esqInfIzq.~Coordenada();
	esqSupDer.~Coordenada();
	centroCuadrante.~Coordenada();
	numCuerpos=0;
	nodoPadre=NULL;
	cuerpoInterior=NULL;

	for(int i=0; i<4; i++){
		if(hijosCuadrante[i]!=NULL)
			hijosCuadrante[i]->~BHNode();
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

Coordenada BHNode::getInfIzq() const{
	return esqInfIzq;
}

// --------------------------------------------------- //

Coordenada BHNode::getSupDer() const{
	return esqSupDer;
}

// --------------------------------------------------- //

Coordenada BHNode::getCentroCuad() const{
	return centroCuadrante;
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

BHNode * BHNode::obtenerCuadrante(Coordenada coordCuerpo){
	assert(this->esHoja()==false); //Solo si ya está expandido podemos obtener cuadrantes.

	float x=coordCuerpo.getX(), y=coordCuerpo.getY();
	float xCentro=centroCuadrante.getX(), yCentro=centroCuadrante.getY();
	BHNode* aux=NULL;

	if(x<=xCentro && y>=yCentro) //Noroeste
		aux=hijosCuadrante[0];
	else if(x>=xCentro && y>=yCentro) //Noreste
		aux=hijosCuadrante[1];
	else if(x<=xCentro && y<=yCentro) //Suroeste
		aux=hijosCuadrante[2];
	else if(x>=xCentro && y<=yCentro) //Sureste
		aux=hijosCuadrante[3];
	else //No está en este cuadrante.
		aux=NULL;

	return aux;
}

// --------------------------------------------------- //


/*  _________
 * |    |    |
 * |__0_|_1__|  
 * |	|	 |
 * |__2_|_3__|
 */

void BHNode::expandirNodo(){
	assert(this->esHoja()==true);

	Coordenada infIzq0(esqInfIzq.getX(), centroCuadrante.getY());
	Coordenada supDer0(centroCuadrante.getX(), esqSupDer.getY());

	hijosCuadrante[0]=new BHNode(infIzq0, supDer0, this);

	Coordenada infIzq1(centroCuadrante);
	Coordenada supDer1(esqSupDer);

	hijosCuadrante[1]=new BHNode(infIzq1, supDer1, this);

	Coordenada infIzq2(esqInfIzq);
	Coordenada supDer2(centroCuadrante);

	hijosCuadrante[2]=new BHNode(infIzq2, supDer2, this);

	Coordenada infIzq3(centroCuadrante.getX(), esqInfIzq.getY());
	Coordenada supDer3(esqSupDer.getX(), centroCuadrante.getY());

	hijosCuadrante[3]=new BHNode(infIzq3, supDer3, this);
}

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

	compX=(esqSupDer.getX()-esqInfIzq.getX())/2+esqInfIzq.getX();
	compY=(esqSupDer.getY()-esqInfIzq.getY())/2+esqInfIzq.getY();

	coord=Coordenada(compX, compY);
}

// --------------------------------------------------- //

bool BHNode::estaDentro(Coordenada coord){
	bool contenido=false;
	float xCord=coord.getX(), yCord=coord.getY();
	
	if(xCord>=esqInfIzq.getX() && xCord<=esqSupDer.getX() &&
		yCord>=esqInfIzq.getY() && yCord<=esqSupDer.getY())
		contenido=true;

	return contenido;
}