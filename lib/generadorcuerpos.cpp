#include "generadorcuerpos.h"

GeneradorCuerpos::GeneradorCuerpos() {
	numCuerpos = 0;
}

GeneradorCuerpos::GeneradorCuerpos(const Coordenada &coor1, const Coordenada &coor2, const double &m, const int &n) {
	esquina1 = coor1;
	esquina2 = coor2;
	
	masa = m;
	numCuerpos = n;

	generador();
}

GeneradorCuerpos::~GeneradorCuerpos() {
	numCuerpos = 0;
}

void GeneradorCuerpos::imprimeFichero(const string &file) {
	ofstream fo;

	fo.open(file.c_str(), ios::out);

	if(fo.is_open())
	{
		fo << numCuerpos << endl;

		fo << esquina1.getX() << " " << esquina1.getY() << " " << esquina2.getX() << " " << esquina2.getY() << endl;

		for(set<string>::iterator it=cuerpos.begin(); it!=cuerpos.end(); it++)
			fo << *it << endl;

		fo.close();
	}
}

void GeneradorCuerpos::generador() {
	float minX = esquina1.getX();
	float maxX = esquina2.getX();
	float minY = esquina1.getY();
	float maxY = esquina2.getY();
	srand(time(NULL));//srand(0);
	int insertados=0;

	for (int i = 0; insertados<numCuerpos; i++)
	{
		float x=0.0, y=0.0;

		if((maxX-minX)/numCuerpos>0.15){
			x=minX + fmod(rand(),(maxX - minX));
			y = minY + fmod(rand(),(maxY - minY));
		}
		else{ //Este genera coordenadas con decimales.
			x=minX + (float)rand()/((float)RAND_MAX/(maxX-minX));
			y=minY + (float)rand()/((float)RAND_MAX/(maxY-minY));
		}

		ostringstream stream;
		stream << x << ' ' << y << ' ' << masa;

		if(cuerpos.insert(stream.str()).second) //Insertado correctamente.
			insertados++;
	}
}
