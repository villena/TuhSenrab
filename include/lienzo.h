#ifndef _lienzo_h
#define _lienzo_h

#include <iostream>
#include "coordenada.h"

using namespace std;


class Lienzo{

	private:
		string data;

	public:
		Lienzo(); //Constructor por defecto

		void drawS(Coordenada InfIzq, Coordenada SupDer, float l); //Añade un cuadrado dadas las coordenadas InfIzq, SupDer, y el lado

		void drawS(Coordenada InfIzq, Coordenada SupDer); //Añade un cuadrado dados InfIzq y SupDer

		void drawC(Coordenada c, double masa); //Añade un circulo en c de radio masa

		void saveFile(); //Guarda el archivo

		string Convert(float f);

};

#endif
