#include <iostream>
#include <math.h>
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

float Coordenada::distanciaEuclidea(Coordenada otra){
	float distancia=0.0, subX=0.0, subY=0.0;

	subX=x-otra.getX();
	subY=y-otra.getY();
	distancia=sqrt(pow(subX,2)+pow(subY,2));

	return distancia;
}

// --------------------------------------------------- //
/*
Coordenada Coordenada::getSimetrica(const Coordenada &original, const int &origen, const int &destino, const int &size){
	Coordenada simetrica(original);
	float pivote = size/2;
//		 ___________
//  	|     |     |
//  	|  ·---->1  |
//		|__|_\|_____|
//  	|  v  |\_   |
//  	|  2  |  3  |
//		|_____|_____|
	if(origen==0){
		switch (destino){
			case 1:
				simetrica.setX(pivote + fabs(pivote-original.getX()));
				break;
			
			case 2:
				simetrica.setY(pivote + fabs(pivote-original.getY()));
				break;
			
			case 3:
				simetrica.setX(pivote + fabs(pivote-original.getX()));
				simetrica.setY(pivote + fabs(pivote-original.getY()));
				break;
		}
	}
//		 ___________
//  	|     |     |
//  	|  0<----·  |
//		|_____|/_|__|
//  	|   _/|  v  |
//  	|  2  |  3  |
//		|_____|_____|
	else if(origen==1){
		switch (destino){
			case 0:
				simetrica.setX(pivote - fabs(pivote-original.getX()));
				break;
			
			case 2:
				simetrica.setX(pivote - fabs(pivote-original.getX()));
				simetrica.setY(pivote + fabs(pivote-original.getY()));
				break;
			
			case 3:
				simetrica.setY(pivote + fabs(pivote-original.getY()));
				break;
		}
	}
//		 ___________
//  	|     |     |
//  	|  0  | _1  |
//		|__^__|/____|
//  	|  | /|     |
//  	|  ·---->3  |
//		|_____|_____|
	else if(origen==2){
		switch (destino){
			case 0:
				simetrica.setY(pivote - fabs(pivote-original.getY()));
				break;
			
			case 1:
				simetrica.setX(pivote + fabs(pivote-original.getX()));
				simetrica.setY(pivote - fabs(pivote-original.getY()));
				break;
			
			case 3:
				simetrica.setX(pivote + fabs(pivote-original.getX()));
				break;
		}
	}
//		 ___________
//  	|     |     |
//  	|  0_ |  1  |
//		|____\|__^__|
//  	|     |\ |  |
//  	|  2<----·  |
//		|_____|_____|
	else if(origen==3){
		switch (destino){
			case 0:
				simetrica.setX(pivote - fabs(pivote-original.getX()));
				simetrica.setY(pivote - fabs(pivote-original.getY()));
				break;
			
			case 1:
				simetrica.setY(pivote - fabs(pivote-original.getY()));
				break;
			
			case 2:
			simetrica.setX(pivote - fabs(pivote-original.getX()));
				break;
		}
	}

	return simetrica;
}
*/
// --------------------------------------------------- //

ostream & operator<<(ostream &op, const Coordenada &coord){
	op << "(" << coord.getX() << ", " << coord.getY() << ")";

	return op;
}