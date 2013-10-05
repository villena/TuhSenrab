#include <iostream>
#include "bhnode.h"

using namespace std;

int main(void){
	//Prueba sobre coordenadas.
	cout << "TEST DE COORDENADA" << endl;

	Coordenada coord1;
	Coordenada coord2(4, 5);
	Coordenada coord3(coord2);

	cout << "Constructor por defecto." << endl;
	cout << "Coord1.x: " << coord1.getX() << endl;
	cout << "Coord1.y: " << coord1.getY() << endl;

	cout << "Constructor con parámetros." << endl;
	cout << "Coord2.x: " << coord2.getX() << endl;
	cout << "Coord2.y: " << coord2.getY() << endl;

	cout << "Constructor de copia." << endl;
	cout << "Coord3.x: " << coord3.getX() << endl;
	cout << "Coord3.y: " << coord3.getY() << endl;

	cout << "Igualdad 1." << endl;
	if(coord1==coord2)
		cout << "Ha fallado." << endl;
	else
		cout << "OK" << endl;

	cout << "Igualdad 2." << endl;
	if(coord2==coord3)
		cout << "OK" << endl;
	else
		cout << "Ha fallado." << endl;

	cout << "Desigualdad 1." << endl;
	if(coord1!=coord2)
		cout << "OK" << endl;
	else
		cout << "Ha fallado." << endl;

	cout << "Desigualdad 2." << endl;
	if(coord3!=coord2)
		cout << "Ha fallado." << endl;
	else
		cout << "OK" << endl;

	return 0;
}