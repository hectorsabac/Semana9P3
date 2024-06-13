#include "Funcion.h"

Funcion::Funcion(fstream& file) : fcont(file){}

Funcion::~Funcion() {
	fcont.close();
}

void Funcion::escribir_o_leer(bool escribir) {
	for (int i = 0; i < 6; ++i) {
		if (escribir) {
			Contacto cont("FALTA TELEFONO", "Nombre " + to_string(i), i);
			fcont.write(reinterpret_cast<char*>(&cont), sizeof(Contacto));
		}
		else {
			Contacto cont;
			fcont.seekp(i * sizeof(Contacto));
			fcont.read(reinterpret_cast<char*>(&cont), sizeof(Contacto));
			cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
		}
	}
}

void Funcion::leer_el_3(Contacto& cont) {
	fcont.seekp(3 * sizeof(Contacto));
	fcont.read(reinterpret_cast<char*>(&cont), sizeof(Contacto));
	cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
}

void Funcion::escribir_el_3(Contacto& cont) {
	Contacto temp("5000", "NOMBRE 5 -> 5000", 5000);
	cont = temp;
	fcont.seekp(3 * sizeof(Contacto));
	fcont.write(reinterpret_cast<char*>(&cont), sizeof(Contacto));
}


void Funcion::cambios() {
	Contacto cont;
	leer_el_3(cont);
	escribir_el_3(cont);
	leer_el_3(cont);
}