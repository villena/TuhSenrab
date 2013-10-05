#include <iostream>
#include "bhnode.h"

using namespace std;

int main(void){
	//Prueba sobre coordenadas.
	cout << "TEST DE COORDENADA" << endl;

	Coordenada coord0(-2, -4);
	Coordenada coord1;
	Coordenada coord2(4, 5);
	Coordenada coord3(coord2);
	Coordenada coord4=coord1;

	cout << "Constructor con negativas" << endl;
	cout << "Coord0.x: " << coord0.getX() << endl;
	cout << "Coord0.y: " << coord0.getY() << endl;	

	cout << "Constructor por defecto." << endl;
	cout << "Coord1.x: " << coord1.getX() << endl;
	cout << "Coord1.y: " << coord1.getY() << endl;

	cout << "Constructor con parámetros." << endl;
	cout << "Coord2.x: " << coord2.getX() << endl;
	cout << "Coord2.y: " << coord2.getY() << endl;

	cout << "Constructor de copia." << endl;
	cout << "Coord3.x: " << coord3.getX() << endl;
	cout << "Coord3.y: " << coord3.getY() << endl;

	cout << "Asignación." << endl;
	cout << "Coord4.x: " << coord4.getX() << endl;
	cout << "Coord4.y: " << coord4.getY() << endl;

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

	// --------------------------------------------------- //

	//Prueba sobre cuerpo.
	cout << endl << "TEST DE CUERPO" << endl;

	Coordenada coordAux(1,1);

	Cuerpo cuerpo1;
	Cuerpo cuerpo2(1, 2, 3.0);
	Cuerpo cuerpo3(coordAux, 4.0);

	cout << "Constructor por defecto." << endl;
	cout << "Posicion.x: " << cuerpo1.getPosicion().getX() << endl;	
	cout << "Posicion.y: " << cuerpo1.getPosicion().getY() << endl;
	cout << "Masa: " << cuerpo1.getMasa() << endl;

	cout << "Constructor con componentes." << endl;
	cout << "Posicion.x: " << cuerpo2.getPosicion().getX() << endl;	
	cout << "Posicion.y: " << cuerpo2.getPosicion().getY() << endl;	
	cout << "Masa: " << cuerpo2.getMasa() << endl;

	cout << "Constructor con coordenada." << endl;
	cout << "Posicion.x: " << cuerpo3.getPosicion().getX() << endl;	
	cout << "Posicion.y: " << cuerpo3.getPosicion().getY() << endl;	
	cout << "Masa: " << cuerpo3.getMasa() << endl;

	cout << "Destructor." << endl;
	cuerpo3.~Cuerpo();
	cout << "Posicion.x: " << cuerpo3.getPosicion().getX() << endl;	
	cout << "Posicion.y: " << cuerpo3.getPosicion().getY() << endl;	
	cout << "Masa: " << cuerpo3.getMasa() << endl;

	return 0;
}