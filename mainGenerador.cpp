#include <iostream>
#include "generadorcuerpos.h"
using namespace std;

int main(int argc, const char* argv[]) {
	if(argc!=2){
		cout << "ERROR. Llamada incorrecta: mainGenerador [num_cuerpos]" << endl;
		return -1;
	}

	Coordenada coord1(0, 0);
	Coordenada coord2(500, 500);

	GeneradorCuerpos generador(coord1, coord2, 1, atoi(argv[1]));

	generador.imprimeFichero("ficherosCuerpos/Prueba1.txt");
}