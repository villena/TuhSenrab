#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "lienzo.h"
#include "coordenada.h"

using namespace std;

// --------------------------------------------------- //

Lienzo::Lienzo(){
	data = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
}

// --------------------------------------------------- //
//El punto de inicio de dibujo es la esquina superior izquierda.

void Lienzo::drawSquare(Coordenada supIzq, float lado){
	string xLienzo="", yLienzo="", ladoLienzo="";

	xLienzo=floatToString(supIzq.getX());
	yLienzo= floatToString(supIzq.getY());
	ladoLienzo=floatToString(lado);

	data += "<rect x=\"" + xLienzo + "\" y=\"" + yLienzo; 
	data += "\" width=\"" + ladoLienzo + "\" height=\"" + ladoLienzo + "\" ";
	data += "fill=\"transparent\" ";
	data += "stroke=\"green\" ";
	data += "stroke-width=\"1\"/>";
	data += '\n';
}

// --------------------------------------------------- //

void Lienzo::drawSquare(Coordenada supIzq, Coordenada infDer){
	float lado = fabs(infDer.getX() - supIzq.getX());

	drawSquare(supIzq, lado);
}

// --------------------------------------------------- //

void Lienzo::drawCircle(Coordenada coord, double radioObjeto){
	string xCentro="", yCentro="", radio="";

	xCentro=floatToString(coord.getX());
	yCentro=floatToString(coord.getY());
	radio=floatToString(radioObjeto);

	data += "<circle cx=\"" + xCentro + "\" cy=\""+ yCentro + "\" r=\"" + radio +"\" ";
	data += "stroke=\"black\" ";
	data += "stroke-width=\"1\" ";
	data += "fill=\"blue\"/>";
	data += '\n';
}

// --------------------------------------------------- //

void Lienzo::saveFile(){
	ofstream file;

	data += "</svg>";
	
  	file.open ("draw.svg", ios::out);
  	file << data;
  	file.close();
}

// --------------------------------------------------- //

void Lienzo::resetLienzo(){
	data = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"> \n";
}

// --------------------------------------------------- //
// --------------------------------------------------- //
// --------------------------------------------------- //

string Lienzo::floatToString(float num){
	ostringstream buffer;

	buffer << num;
	string str = buffer.str();

	return str;
}