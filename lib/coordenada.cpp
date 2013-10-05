#include <iostream>
#include "coordenada.h"

using namespace std;

// --------------------------------------------------- //

Coordenada::Coordenada(){
	x=0;
	y=0;
}

// --------------------------------------------------- //

Coordenada::Coordenada(float x, float y){
	this->x=x;
	this->y=y;
}

// --------------------------------------------------- //

Coordenada::Coordenada(const Coordenada &coord){
	x=coord.getX();
	y=coord.getY();
}

// --------------------------------------------------- //

Coordenada::~Coordenada(){
	x=0;
	y=0;
}

// --------------------------------------------------- //

bool Coordenada::operator==(const Coordenada &coord){
	if(x==coord.getX() && y==coord.getY())
		return true;
	else
		return false;
} 

// --------------------------------------------------- //

bool Coordenada::operator!=(const Coordenada &coord){
	if(*this==coord)
		return false;
	else
		return true;
} 

// --------------------------------------------------- //

float Coordenada::getX() const{
	return x;
}

// --------------------------------------------------- //

float Coordenada::getY() const{
	return y;
}