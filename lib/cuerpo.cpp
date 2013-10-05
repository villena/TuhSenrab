#include <iostream>
#include "cuerpo.h"
#include "coordenada.h"

using namespace std;

// --------------------------------------------------- //

Cuerpo::Cuerpo(){
	posicion=Coordenada();
	masa=0.0;
}

// --------------------------------------------------- //

Cuerpo::Cuerpo(float x, float y, double m){
	posicion=Coordenada(x, y);
	masa=m;
}

// --------------------------------------------------- //

Cuerpo::Cuerpo(Coordenada coord, double m){
	posicion=coord;
	masa=m;
}

// --------------------------------------------------- //

Cuerpo::Cuerpo(const Cuerpo &cuerpo){
	posicion=cuerpo.getPosicion();
	masa=cuerpo.getMasa();
}

// --------------------------------------------------- //

Cuerpo::~Cuerpo(){
	posicion.~Coordenada();
	masa=0.0;
}

// --------------------------------------------------- //

Coordenada Cuerpo::getPosicion() const{
	return posicion;
}

// --------------------------------------------------- //

double Cuerpo::getMasa() const{
	return masa;
}