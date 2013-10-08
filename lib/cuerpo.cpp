#include <iostream>
#include "cuerpo.h"
#include "coordenada.h"

using namespace std;

// --------------------------------------------------- //

Cuerpo::Cuerpo(){
	posicion=Coordenada();
	masa=0.0;
	fuerza=0.0;
}

// --------------------------------------------------- //

Cuerpo::Cuerpo(float x, float y, double m){
	float aux=0.0, auy=0.0;
	
	if(x>0.0)
		aux=x;
	if(y>0.0)
		auy=y;

	posicion=Coordenada(aux, auy);
	masa=m;
	fuerza=0.0;
}

// --------------------------------------------------- //

Cuerpo::Cuerpo(Coordenada coord, double m){
	posicion=coord;
	masa=m;
	fuerza=0.0;
}

// --------------------------------------------------- //

Cuerpo::Cuerpo(const Cuerpo &cuerpo){
	posicion=cuerpo.getPosicion();
	masa=cuerpo.getMasa();
	fuerza=cuerpo.getMasa();
}

// --------------------------------------------------- //

Cuerpo::~Cuerpo(){
	posicion.~Coordenada();
	masa=0.0;
	fuerza=0.0;
}

// --------------------------------------------------- //

Coordenada Cuerpo::getPosicion() const{
	return posicion;
}

// --------------------------------------------------- //

double Cuerpo::getMasa() const{
	return masa;
}

// --------------------------------------------------- //

double Cuerpo::getFuerza() const{
	return fuerza;
}

// --------------------------------------------------- //

void Cuerpo::setFuerza(double f)
{
	fuerza=f;
}

// --------------------------------------------------- //

ostream & operator<<(ostream &op, const Cuerpo &cuerpo){
	op << "[" << cuerpo.getPosicion() << ", " << cuerpo.getMasa() << "]";

	return op;
}
