#include <iostream>
#include "generadorcuerpos.h"
using namespace std;

int main(int argc, const char* argv[]) {
	if(argc!=3){
		cout << "ERROR. Llamada incorrecta: mainGenerador [num_cuerpos] [nom_fichero_guardar]" << endl;
		return -1;
	}

	Coordenada coord1(0, 0);
	Coordenada coord2(5000, 5000);

	GeneradorCuerpos generador(coord1, coord2, 1, atoi(argv[1]));

	generador.imprimeFichero(argv[2]);
}