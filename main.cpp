#include <iostream>
#include "bhnode.h"

//#define COORD
//#define CUERPO
#define BHNODE

using namespace std;

int main(void){

	#ifdef COORD
	//Prueba sobre coordenadas.
	cout << "TEST DE COORDENADA" << endl;

	Coordenada coord0(-2, -4);
	Coordenada coord1;
	Coordenada coord2(4, 5);
	Coordenada coord3(coord2);

	cout << "Constructor con negativas" << endl;
	cout << "Coord0: " << coord0 << endl;

	cout << "Constructor por defecto." << endl;
	cout << "Coord1: " << coord1 << endl;

	cout << "Constructor con parámetros." << endl;
	cout << "Coord2: " << coord2 << endl;

	cout << "Constructor de copia." << endl;
	cout << "Coord3: " << coord3 << endl;

	cout << "Asignación." << endl;
	Coordenada coord4=coord1;
	cout << "Coord4: " << coord4 << endl;

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

	#endif

	// --------------------------------------------------- //


	#ifdef CUERPO
	//Prueba sobre cuerpo.
	cout << endl << "TEST DE CUERPO" << endl;

	Coordenada coordAux(1,1);

	Cuerpo cuerpo1;
	Cuerpo cuerpo2(1, 2, 3.0);
	Cuerpo cuerpo3(coordAux, 4.0);

	cout << "Constructor por defecto." << endl;
	cout << "Posicion: " << cuerpo1.getPosicion() << endl;
	cout << "Masa: " << cuerpo1.getMasa() << endl;

	cout << "Constructor con componentes." << endl;
	cout << "Posicion: " << cuerpo2.getPosicion() << endl;
	cout << "Masa: " << cuerpo2.getMasa() << endl;

	cout << "Constructor con coordenada." << endl;
	cout << "Posicion: " << cuerpo3.getPosicion() << endl;
	cout << "Masa: " << cuerpo3.getMasa() << endl;

	cout << "Destructor." << endl;
	cuerpo3.~Cuerpo();
	cout << "Posicion: " << cuerpo3.getPosicion() << endl;
	cout << "Masa: " << cuerpo3.getMasa() << endl;

	#endif

	// --------------------------------------------------- //


	#ifdef BHNODE
	//Prueba sobre bhnode.
	cout << endl << "TEST DE BHNODE" << endl;

	Coordenada coordA(0, 0);
	Coordenada coordB(5, 5);

	BHNode nodoPadre;
	BHNode nodo1(coordA, coordB, nodoPadre);

	cout << "Constructor por defecto." << endl;
	cout << "Masa: " << nodoPadre.getMasa() << endl;
	cout << "CentroMasa: " << nodoPadre.getCentroMasa() << endl;
	cout << "esqInfIzq: " << nodoPadre.getInfIzq() << endl;
	cout << "esqSupDer: " << nodoPadre.getSupDer() << endl;
	cout << "CentroCuad: " << nodoPadre.getCentroCuad() << endl;
	cout << "Cuerpos: " << nodoPadre.getNumCuerpos() << endl;
	cout << "Padre: " << nodoPadre.getPadre() << endl;
	cout << "Raíz?: " << nodoPadre.esRaiz() << endl;
	cout << "Hoja?: " << nodoPadre.esHoja() << endl;

	cout << endl << "Constructor con parámetros." << endl;
	cout << "Masa: " << nodo1.getMasa() << endl;
	cout << "CentroMasa: " << nodo1.getCentroMasa() << endl;
	cout << "esqInfIzq: " << nodo1.getInfIzq() << endl;
	cout << "esqSupDer: " << nodo1.getSupDer() << endl;
	cout << "CentroCuad: " << nodo1.getCentroCuad() << endl;
	cout << "Cuerpos: " << nodo1.getNumCuerpos() << endl;
	cout << "Padre: " << nodo1.getPadre() << endl;
	cout << "Raíz?: " << nodo1.esRaiz() << endl;
	cout << "Hoja?: " << nodo1.esHoja() << endl;

	#endif

	return 0;
}