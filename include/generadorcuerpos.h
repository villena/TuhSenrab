#ifndef _generadorcuerpos_h
#define _generadorcuerpos_h

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include "cuerpo.h"

using namespace std;


/*
 * Clase encargada de generar cuerpos únicos del escenario.
 * Incluye método para realizar una salida a fichero.
 */
class GeneradorCuerpos
{
	public:
		GeneradorCuerpos();
		
		GeneradorCuerpos(const Coordenada &, const Coordenada &, const double &, const int &);
		
		~GeneradorCuerpos();

		void imprimeFichero(const string &);

		void generador();

	private:
		Coordenada esquina1;
		Coordenada esquina2;
		double masa;
		int numCuerpos;
		std::vector<Cuerpo> cuerpos;
};

#endif