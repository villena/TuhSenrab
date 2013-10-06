#include <iostream>
#include "coordenada.h"

using namespace std;

// --------------------------------------------------- //

Coordenada::Coordenada(){
	x=0.0;
	y=0.0;
}

// --------------------------------------------------- //

Coordenada::Coordenada(float x, float y){
	if(x>=0.0)
		this->x=x;
	else
		this->x=0.0;

	if(y>=0.0)
		this->y=y;
	else
		this->y=0.0;
}

// --------------------------------------------------- //

Coordenada::Coordenada(const Coordenada &coord){
	x=coord.getX();
	y=coord.getY();
}

// --------------------------------------------------- //

Coordenada::~Coordenada(){
	x=0.0;
	y=0.0;
}

// --------------------------------------------------- //

Coordenada & Coordenada::operator=(const Coordenada &coord){
	if(this!=&coord){
		x=coord.getX();
		y=coord.getY();
	}

	return *this;
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

// --------------------------------------------------- //

void Coordenada::setX(float newX){
	if(newX>0.0)
		x=newX;
	else
		x=0.0;
}

// --------------------------------------------------- //

void Coordenada::setY(float newY){
	if(newY>0.0)
		y=newY;
	else
		y=0.0;
}

// --------------------------------------------------- //

ostream & operator<<(ostream &op, const Coordenada &coord){
	op << "(" << coord.getX() << ", " << coord.getY() << ")";

	return op;
}