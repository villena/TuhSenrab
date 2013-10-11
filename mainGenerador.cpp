#include <iostream>
#include "generadorcuerpos.h"
using namespace std;

int main(void) {

	Coordenada coord1(0, 0);
	Coordenada coord2(40, 50);

	GeneradorCuerpos generador(coord1, coord2, 1000, 50);

	generador.imprimeFichero("Prueba1.txt");
}