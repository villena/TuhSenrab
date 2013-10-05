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
		int x; //Componente 'x' de la coordenada 2D.
		int y; //Componente 'y' de la coordenada 2D.

	public:
		Coordenada(); //Constructor por defecto.

		Coordenada(int, int); //Constructor con las dos componentes.

		Coordenada(const Coordenada &); //Constructor de copia.

		~Coordenada(); //Destructor.

		bool operator==(const Coordenada &); //Sobrecarga operador igualdad.

		bool operator!=(const Coordenada &); //Sobrecarga operador desigualdad.

		int getX(); //Getter de la componente 'x'.

		int getY(); //Getter de la componente 'y'.
};

#endif