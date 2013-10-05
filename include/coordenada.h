#ifndef _coordenada_h
#define _coordenada_h

#include <iostream>

using namespace std;

/*
 * Esta clase representa una coordenada 2D con sus
 * dos componentes.
 */
class Coordenada{
	private:
		float x; //Componente 'x' de la coordenada 2D.
		float y; //Componente 'y' de la coordenada 2D.

	public:
		Coordenada(); //Constructor por defecto.

		Coordenada(float, float); //Constructor con las dos componentes.

		Coordenada(const Coordenada &); //Constructor de copia.

		~Coordenada(); //Destructor.

		bool operator==(const Coordenada &); //Sobrecarga operador igualdad.

		bool operator!=(const Coordenada &); //Sobrecarga operador desigualdad.

		float getX() const; //Getter de la componente 'x'.

		float getY() const; //Getter de la componente 'y'.
};

#endif