#include <iostream>
#include "coordenada.h"
#include "cuerpo.h"
#include "bhnode.h"

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

	for(int i=0; i<4; i++)
		hijosCuadrante[i]=NULL;
}

// --------------------------------------------------- //

BHNode::BHNode(Coordenada infIzq, Coordenada supDer, BHNode *padre){
	masa=0.0;
	centroMasa=Coordenada();
	esqInfIzq=infIzq;
	esqSupDer=supDer;
	centroCuadrante=calculaCentro();
	numCuerpos=0;
	nodoPadre=padre;

	for(int i=0; i<4; i++)
		hijosCuadrante[i]=NULL;
}

// --------------------------------------------------- //

BHNode::BHNode(const BHNode &bhnode){
	masa=bhnode.getMasa();
	centroMasa=bhnode.getCentroMasa();
	esqInfIzq=bhnode.getInfIzq();
	esqSupDer=bhnode.getSupDer();
	centroCuadrante=bhnode.getCentroCuad();
	numCuerpos=bhnode.getNumCuerpos();
	nodoPadre=bhnode.getPadre();
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

BHNode * BHNode::obtenerCuadrante(Cuerpo cuerpo){
	Coordenada coordCuerpo=cuerpo.getPosicion();
	BHNode* aux=NULL;

	if(this->estaDentro(coordCuerpo)){ //Dentro del cuadrante. Miramos a qué hijo va.
		float x=coordCuerpo.getX(), y=coordCuerpo.getY();
		float xCentro=centroCuadrante.getX(), yCentro=centroCuadrante.getY();

		if(x<=xCentro && y>=yCentro) //Noroeste
			aux=hijosCuadrante[0];
		else if(x>=xCentro && y>=yCentro) //Noreste
			aux=hijosCuadrante[1];
		else if(x<=xCentro && y<=yCentro) //Suroeste
			aux=hijosCuadrante[2];
		else //Sureste
			aux=hijosCuadrante[3];
	}

	return aux;
}

// --------------------------------------------------- //
// --------------------------------------------------- //
// --------------------------------------------------- //

Coordenada BHNode::calculaCentro(){
	float compX, compY;

	compX=esqSupDer.getX()-esqInfIzq.getX();
	compY=esqSupDer.getY()-esqInfIzq.getY();

	return Coordenada(compX, compY);
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