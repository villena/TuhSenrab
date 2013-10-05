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

BHNode::BHNode(Coordenada infIzq, Coordenada supDer, BHNode &padre){
	masa=0.0;
	centroMasa=Coordenada();
	esqInfIzq=infIzq;
	esqSupDer=supDer;
	this->calculaCentro(centroCuadrante);
	numCuerpos=0;
	nodoPadre=&padre;
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
		*cuerpoInterior=cuerpo;

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

void BHNode::expandirNodo(){
	assert(this->esHoja()==true);

	for(int i=0; i<4; i++)
		hijosCuadrante[i]=new BHNode();
}

// --------------------------------------------------- //
// --------------------------------------------------- //
// --------------------------------------------------- //

void BHNode::calculaCentro(Coordenada &coord){ 
	float compX, compY;

	compX=(esqSupDer.getX()-esqInfIzq.getX())/2;
	compY=(esqSupDer.getY()-esqInfIzq.getY())/2;

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