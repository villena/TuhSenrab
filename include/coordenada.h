#ifndef _coordenada_h
#define _coordenada_h

#include <iostream>

using namespace std;

/*
 * Esta clase representa una coordenada 2D con sus
 * dos componentes. Se aceptan solo positivas.
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

		Coordenada & operator=(const Coordenada &); //Sobrecarga operador asignación.

		bool operator==(const Coordenada &); //Sobrecarga operador igualdad.

		bool operator!=(const Coordenada &); //Sobrecarga operador desigualdad.

		float getX() const; //Getter de la componente 'x'.

		float getY() const; //Getter de la componente 'y'.

		void setX(float); //Setter de la componente 'x'.

		void setY(float); //Setter de la componente 'y'.

		float distanciaEuclidea(Coordenada); //Distancia entre dos puntos.

		friend ostream & operator<<(ostream &, const Coordenada &); //Sobrecarga operador salida.
};

#endif