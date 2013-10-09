#ifndef _bhnode_h
#define _bhnode_h

#include <iostream>
#include "coordenada.h"
#include "cuerpo.h"

using namespace std;

/*
 * Esta clase representa un nodo Cuadrante para el
 * método de cálculo de problemas n-body llamado
 * de Barnes-hut. Cada cuadrante tiene sus coordenadas
 * y dentro de ellos hay cuerpos.
 */
class BHNode{
	private:
		double masa; //Masa en el cuadrante.
		Coordenada centroMasa; //Centro de masa en el cuadrante.
		Coordenada esqInfIzq; //Coordenada de la esquina inferior izquierda del cuadrante.
		Coordenada esqSupDer; //Coordenada de la esquina superior derecha del cuadrante.
		Coordenada centroCuadrante; //Centro del cuadrante.
		unsigned int numCuerpos; //Número de cuerpos dentro del cuadrante.
		BHNode *nodoPadre; //Puntero al nodo padre del cuadrante.
		BHNode *hijosCuadrante[4]; //Punteros a los 0 o 4 hijos que tiene un nodo.
		Cuerpo *cuerpoInterior; //Puntero Cuerpo contenido en este cuadrante.
		

		void calculaCentro(Coordenada &); //Calcula el centro del cuadrante.

		bool estaDentro(Coordenada); //Calcula si la coordenad está dentro del cuadrante.

	public:
		BHNode(); //Constructor por defecto.

		BHNode(Coordenada, Coordenada, BHNode *); //Constructor con las esquinas y el padre.

		~BHNode(); //Destructor.

		double getMasa() const; //Getter de la masa dentro del cuadrante.

		Coordenada getCentroMasa() const; //Getter del centro de masas.

		Coordenada getInfIzq() const; //Getter de la coordenada inferior izquierda.

		Coordenada getSupDer() const; //Getter de la coordenada superior derecha.

		Coordenada getCentroCuad() const; //Getter del centro del cuadrante.

		unsigned int getNumCuerpos() const; //Getter de la cantidad de cuerpos dentro del cuadrante.

		BHNode * getPadre() const; //Getter del padre.

		bool esRaiz() const; //Devuelve TRUE si es un nodo raíz.

		bool esHoja() const; //Devuelve TRUE si es un nodo hoja.

		bool introducirCuerpo(Cuerpo &); //Si puede introducir el cuerpo devuelve TRUE.

		double calculaFuerza(const Cuerpo &); //Calcula la fuerza que ejerce el árbol sobre el cuerpo.

		void calcularDistribucionMasas(); //Calcula la distribución de masas en el nodo.

		BHNode * obtenerCuadrante(Coordenada); //Obtiene el cuadrante en el que entra la coordenada.

		void expandirNodo(); //Expande un nodo: crea sus 4 hijos.

		friend ostream & operator<<(ostream &, const BHNode &); //Sobrecarga operador salida.
};

#endif