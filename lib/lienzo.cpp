#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "lienzo.h"
#include "coordenada.h"



using namespace std;

Lienzo::Lienzo(){
	data = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"> \n";
}

void Lienzo::drawS(Coordenada InfIzq, Coordenada SupDer, float l){

	//El punto de inicio de dibujo es SupIzq

	string IzX,DeY,sl;
	IzX=Convert(InfIzq.getX());
	DeY=Convert(SupDer.getY());
	sl=Convert(l);

	data += "<rect x=\"" + IzX + "\" y=\"" + DeY + "\" width=\"" + sl + "\" height=\"" + sl + "\" fill=\"transparent\" stroke=\"green\" stroke-width=\"1\"/>" + '\n';
}

void Lienzo::drawS(Coordenada InfIzq, Coordenada SupDer){

	//Calculo del lado

	float l = fabs(SupDer.getX() - InfIzq.getX());

	drawS(InfIzq, SupDer, l);
}

void Lienzo::drawC(Coordenada c, double masa){

	string cx, cy, sm;
	cx=Convert(c.getX());
	cy=Convert(c.getY());
	sm=Convert(masa);

	data += "<circle cx=\"" + cx + "\" cy=\""+ cy + "\" r=\"" + sm + "\" stroke=\"black\" stroke-width=\"0\" fill=\"black\" />" + '\n';
}

void Lienzo::saveFile(){

	data += "</svg> ";

	ofstream file;
  	file.open ("draw.svg", ios::out);
  	file << data;
  	file.close();
}


string Lienzo::Convert(float f)
{
	ostringstream buffer;

	buffer << f;
	string str = buffer.str();

	return str;
}


