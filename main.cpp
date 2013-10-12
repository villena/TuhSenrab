/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * En este programa se utilizará el método de Barnes-hut para simular las fuerzas    *
 * ejercidas entre cuerpos distribuidos en un cuadrante. Estos cuerpos se leerán     *
 * de un fichero ya formateado: primera línea con número de cuerpos a cargar,        *
 * segunda línea con componentes para formar las coordenadas de la esquina superior  *
 * izquierda y la inferior derecha que definan el cuadrante, y por último la lista   *
 * de cuerpos con sus componentes X e Y junto a la masa.							 *
 * Además, se genera un archvio SVG con la situación final del árbol.				 *
 * * * * * * * * * * * * * * * ** * * * * * * * * * * * * * * ** * * * * * * * * * * */

#include <iostream>
#include <fstream>
#include <cassert>
#include "bhnode.h"

const string errorLlamada="ERROR. Llamada incorrecta: main [fichero_cuerpos]";
const string errorLecturaFichero="ERROR. No fue posible abrir el archivo: ";

Cuerpo** leerCuerpos(BHNode *&nodo, int &cantidad, const string nombreFichero){
	ifstream fEntrada;
	string linea="";

	fEntrada.open(nombreFichero.c_str(), ios::in);

	if(fEntrada.is_open()){
		//En la primera línea tenemos la cantidad de cuerpos.
		getline(fEntrada, linea); 

		cantidad=atoi(&linea.c_str()[0]);
		Cuerpo **cuerpos=new Cuerpo*[cantidad];

		for(int i=0; i<cantidad; i++)
			cuerpos[i]=NULL;


		//Esta debe ser la línea con el cuadrante.
		getline(fEntrada, linea); 

		string esqSupIzqX="", esqSupIzqY="";
		string esqInfDerX="", esqInfDerY="";
		float xIzq=0.0, yIzq=0.0, xDer=0.0, yDer=0.0;
		int espacios=0;

		for(int i=0; i<linea.length(); i++){
			if(linea[i]==' ')
				espacios++;
			else if(espacios==0)
				esqSupIzqX+=linea[i];
			else if(espacios==1)
				esqSupIzqY+=linea[i];				
			else if(espacios==2)
				esqInfDerX+=linea[i];				
			else
				esqInfDerY+=linea[i];					
		}

		xIzq=atof(esqSupIzqX.c_str());
		yIzq=atof(esqSupIzqY.c_str());
		xDer=atof(esqInfDerX.c_str());
		yDer=atof(esqInfDerY.c_str());

		Coordenada coord1(xIzq, yIzq);
		Coordenada coord2(xDer, yDer);

		nodo=new BHNode(coord1, coord2, NULL);


		//Ahora vienen los cuerpos.
		getline(fEntrada, linea); 

		int aux=0;
		while(!fEntrada.eof()){
			float x=0.0, y=0.0;
			double m=0.0;
			string compX="", compY="", masa="";
			bool primerWS=false, segundoWS=false;

			for(int i=0; i<linea.length(); i++){
				if(!primerWS){
					if(linea[i]==' ')
						primerWS=true;
					else
						compX+=linea[i];
				}
				else if(!segundoWS){
					if(linea[i]==' ')
						segundoWS=true;
					else
						compY+=linea[i];
				}
				else
					masa+=linea[i];
			}	

			x=atof(compX.c_str());
			y=atof(compY.c_str());
			m=atof(masa.c_str());
			cuerpos[aux]=new Cuerpo(x, y, m);
			aux++;

			getline(fEntrada, linea);
		}
		fEntrada.close();

		return cuerpos;
	}
	else{
		cantidad=-1;
		cout << errorLecturaFichero << nombreFichero << endl;
	}

	return NULL;
}

int main(int argc, const char* argv[]){
	if(argc!=2){
		cout << errorLlamada << endl;
		return -1;
	}

	int cantidad=0;
	string fichero=argv[1];
	Cuerpo** cuerpos;
	BHNode* nodoInit=NULL;

	cuerpos=leerCuerpos(nodoInit, cantidad, fichero);

	assert(cuerpos!=NULL & nodoInit!=NULL);

	cout << "Cuerpos leídos y generados. Nodo inicial creado." << endl;
	cout << "Pasando a introducir los cuerpos." << endl;

	for(int i=0; i<cantidad; i++)
		nodoInit->introducirCuerpo(*cuerpos[i]);

	cout << "Cuerpos introducidos. Pasamos a calcular la distribución de masas." << endl;

	nodoInit->calcularDistribucionMasas();

	cout << "Distribución de masas calculada. Pasamos a calcular la fuerza sobre cada cuerpo." << endl;

	for(int i=0; i<cantidad; i++)
		nodoInit->calculaFuerza(*cuerpos[i]);

	cout << "Fuerza calculada." << endl;

	/*cout << "Pasamos a dibujar lienzo." << endl;
	Lienzo lienzo;
	nodoInit->generaSVG(lienzo);
	lienzo.saveFile("resultadoMain.svg");

	cout << "Lienzo generado y guardado como resultadoMain.svg" << endl;*/

	return 0;
}