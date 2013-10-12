#include <iostream>
#include "generadorcuerpos.h"
using namespace std;

int main(void) {

	Coordenada coord1(0, 0);
	Coordenada coord2(500, 500);

	GeneradorCuerpos generador(coord1, coord2, 1, 50000);

	generador.imprimeFichero("ficherosCuerpos/Prueba1.txt");
}