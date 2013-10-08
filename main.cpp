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

	cout << "Setter X,Y correcto" << endl;
	coord1.setX(4.5); coord1.setY(4.5);
	cout << "Coord1: " << coord1 << endl;

	cout << "Setter X,Y incorrecto" << endl;
	coord1.setX(-4.5); coord1.setY(-4.5);
	cout << "Coord1: " << coord1 << endl;

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
	cout << cuerpo1 << endl;

	cout << "Constructor con componentes." << endl;
	cout << cuerpo2 << endl;

	cout << "Constructor con coordenada." << endl;
	cout << cuerpo3 << endl;

	cout << "Destructor." << endl;
	cuerpo3.~Cuerpo();
	cout << cuerpo3 << endl;

	#endif

	// --------------------------------------------------- //


	#ifdef BHNODE
	//Prueba sobre bhnode.
	cout << endl << "TEST DE BHNODE" << endl;

	Coordenada coordA(0, 0);
	Coordenada coordB(5, 5);

	BHNode nodo0;
	BHNode nodo1(coordA, coordB, &nodo0);

	cout << "Constructor por defecto." << endl;
	cout << "Masa: " << nodo0.getMasa() << endl;
	cout << "CentroMasa: " << nodo0.getCentroMasa() << endl;
	cout << "esqInfIzq: " << nodo0.getInfIzq() << endl;
	cout << "esqSupDer: " << nodo0.getSupDer() << endl;
	cout << "CentroCuad: " << nodo0.getCentroCuad() << endl;
	cout << "Cuerpos: " << nodo0.getNumCuerpos() << endl;
	cout << "Padre: " << nodo0.getPadre() << endl;
	cout << "Raíz?: " << nodo0.esRaiz() << endl;
	cout << "Hoja?: " << nodo0.esHoja() << endl;

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

	// - - - - - - - - - - - - - - - - - - - - //

	BHNode nodoInit(coordA, coordB, NULL);

	cout << endl << "Constructor con parámetros, padre NULL." << endl;
	cout << "Masa: " << nodoInit.getMasa() << endl;
	cout << "CentroMasa: " << nodoInit.getCentroMasa() << endl;
	cout << "esqInfIzq: " << nodoInit.getInfIzq() << endl;
	cout << "esqSupDer: " << nodoInit.getSupDer() << endl;
	cout << "CentroCuad: " << nodoInit.getCentroCuad() << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << "Padre: " << nodoInit.getPadre() << endl;
	cout << "Raíz?: " << nodoInit.esRaiz() << endl;
	cout << "Hoja?: " << nodoInit.esHoja() << endl;

	Cuerpo cuerpoA(1, 1, 1.0);

	cout << endl << "Intentamos introducir el cuerpo " << cuerpoA << endl;
	cout << "Logrado?: " << nodoInit.introducirCuerpo(cuerpoA) << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << nodoInit << endl;


	Cuerpo cuerpoB(4, 4, 1.0);

	cout << endl << "Intentamos introducir el cuerpo " << cuerpoB << endl;
	cout << "Logrado?: " << nodoInit.introducirCuerpo(cuerpoB) << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << nodoInit << endl;


	Cuerpo cuerpoC(1, 4, 1.0);

	cout << endl << "Intentamos introducir el cuerpo " << cuerpoC << endl;
	cout << "Logrado?: " << nodoInit.introducirCuerpo(cuerpoC) << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << nodoInit << endl;


	Cuerpo cuerpoD(3, 3, 1.0);

	cout << endl << "Intentamos introducir el cuerpo " << cuerpoD << endl;
	cout << "Logrado?: " << nodoInit.introducirCuerpo(cuerpoD) << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << nodoInit << endl;


	Cuerpo cuerpoE(4, 1, 1.0);

	cout << endl << "Intentamos introducir el cuerpo " << cuerpoE << endl;
	cout << "Logrado?: " << nodoInit.introducirCuerpo(cuerpoE) << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << nodoInit << endl;


	Cuerpo cuerpoF(3, 4.5, 1.0);

	cout << endl << "Intentamos introducir el cuerpo " << cuerpoF << endl;
	cout << "Logrado?: " << nodoInit.introducirCuerpo(cuerpoF) << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << nodoInit << endl;


	Cuerpo cuerpoG(4.5, 4.5, 1.0);

	cout << endl << "Intentamos introducir el cuerpo " << cuerpoG << endl;
	cout << "Logrado?: " << nodoInit.introducirCuerpo(cuerpoG) << endl;
	cout << "Cuerpos: " << nodoInit.getNumCuerpos() << endl;
	cout << nodoInit << endl;

	cout << endl << "Ahora calculamos la distribución de masas. " << endl;
	nodoInit.calcularDistribucionMasas();
	cout << "Masa: " << nodoInit.getMasa() << endl;
	cout << "Centro masa: " << nodoInit.getCentroMasa() << endl;


	cout << endl << "Prueba Fuerza" << endl;
	cuerpoG.setFuerza(nodoInit.calculaFuerza(cuerpoG));
	cout << "Fuerza " << cuerpoG.getFuerza()<<endl;

	#endif

	return 0;
}

void calculaFuerza(Cuerpo c/*listacuerpos*/, BHNode raiz)
{
	//for(elemento en listacuerpos)
	//{
		c.setFuerza(raiz.calculaFuerza(c));
	//}
}
