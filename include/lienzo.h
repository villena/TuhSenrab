#ifndef _lienzo_h
#define _lienzo_h

#include <iostream>
#include "coordenada.h"

using namespace std;

/*
 * Esta clase representa un lienzo. Se dibujará
 * utilizando código XML y SVG.
 */
class Lienzo{
	private:
		string data; //Contenido del fichero.

		string floatToString(float); //Aux: Pasar float a string.

	public:
		Lienzo(); //Constructor por defecto.

		void drawSquare(Coordenada, Coordenada, float); //Añade un cuadrado dadas las coordenadas InfIzq, SupDer, y el lado.

		void drawSquare(Coordenada, Coordenada); //Añade un cuadrado dadas las coordenadas InfIzq y SupDer.

		void drawCircle(Coordenada, double); //Añade un circulo dados su centro y radio.

		void saveFile(); //Guarda el archivo.

		void resetLienzo(); //Resetea el lienzo.
};

#endif