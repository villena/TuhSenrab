#include <iostream>
#include <fstream>
#include "bhnode.h"

const string errorLecturaFichero="ERROR. No fue posible abrir el archivo: ";

Cuerpo** leerCuerpos(int &cantidad, const string nombreFichero){
	ifstream fEntrada;
	string linea="";

	fEntrada.open(nombreFichero.c_str(), ios::in);

	if(fEntrada.is_open()){
		getline(fEntrada, linea); //En la primera línea tenemos la cantidad de cuerpos.

		cantidad=atoi(&linea.c_str()[0]);
		Cuerpo *cuerpos[cantidad];

		for(int i=0; i<cantidad; i++)
			cuerpos[i]=NULL;

		getline(fEntrada, linea); //Esta debe ser la línea con el cuadrante.
		getline(fEntrada, linea); //Ahora vienen los cuerpos.

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

int main(){
	int cantidad=0;
	string fichero="ejemplo";
	Cuerpo** cuerpos;

	cuerpos=leerCuerpos(cantidad, fichero);

	for(int i=0; i<cantidad; i++)
		cout << *cuerpos[i] << endl;

	return 0;
}