#ifndef _cuerpo_h
#define _cuerpo_h

#include <iostream>
#include "coordenada.h"

#using namespace std;

/*
 * Clase que representa un cuerpo en el espacio. Tiene su
 * masa y su posición 2D.
 */
class Cuerpo{
	private:
		Coordenada posicion; //Coordenadas de la posición del cuerpo.
		double masa; //Masa del cuerpo.

	public:
		Cuerpo(); //Constructor por defecto.

		Cuerpo(int, int, double); //Constructor con todas las componentes.

		Cuerpo(Coordenada, double); //Constructor con coordenada.

		Cuerpo(const Cuerpo &); //Constructor de copia.

		~Cuerpo(); //Destructor.

		Coordenada getCoordenada(); //Getter de la coord con la posición.

		double getMasa(); //Getter de la masa del cuerpo.
};

#endif