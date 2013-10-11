#import "generadorcuerpos.h"

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

		for (int i=0; i < numCuerpos; i++)
		{
			Coordenada c = cuerpos[i].getPosicion();

			fo << c.getX() << " " << c.getY() << " " << cuerpos[i].getMasa() << endl;
		}

		fo << endl;

		fo.close();
	}
}

void GeneradorCuerpos::generador() {
	float minX = esquina1.getX();
	float maxX = esquina2.getX();
	float minY = esquina1.getY();
	float maxY = esquina2.getY();
	srand(0);

	for (int i = 0; i<numCuerpos; i++)
	{
		float x = minX + fmod(rand(),(maxX - minX + 1));
		float y = minY + fmod(rand(),(maxY - minY + 1));

		Cuerpo body(x, y, masa);

		cuerpos.push_back(body);
	}
}
