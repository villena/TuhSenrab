#ifndef _cuerpo_h
#define _cuerpo_h

#include <iostream>
#include "coordenada.h"

using namespace std;

/*
 * Clase que representa un cuerpo en el espacio. Tiene su
 * masa y su posición 2D. 
 */
class Cuerpo{
	private:
		Coordenada posicion; //Coordenadas de la posición del cuerpo.
		double masa; //Masa del cuerpo.
		double fuerza; //Fuerza a la que es sometido el cuerpo.

	public:
		Cuerpo(); //Constructor por defecto.

		Cuerpo(float, float, double); //Constructor con todas las componentes.

		Cuerpo(Coordenada, double); //Constructor con coordenada.

		Cuerpo(const Cuerpo &); //Constructor de copia.

		~Cuerpo(); //Destructor.

		Coordenada getPosicion() const; //Getter de la coord con la posición.

		double getMasa() const; //Getter de la masa del cuerpo.

		double getFuerza() const; //Getter de la fuerza ejercida sobre el cuerpo.

		void setFuerza(double); //Setter de la fuerza ejercida sobre el cuerpo.

		friend ostream & operator<<(ostream &, const Cuerpo &); //Sobrecarga operador salida.

		bool operator==(const Cuerpo &); //Sobrecarga del operador de igualdad

		bool operator!=(const Cuerpo &); //Sobrecarga del operador de desigualdad
};

#endif