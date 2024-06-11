#include "Contacto.h"
using namespace std;
Contacto::Contacto(const string& Tel, const string& Nom, const int Id) {
	establecerTelefono(Tel);
	establecerNombre(Nom);
	id = Id;
}

string Contacto::obtenerTelefono() const {
	return telefono;
}

void copiar_cadena(const string Cadena, char cadena[], int long_max) {
	int longitud = Cadena.size();
	longitud = (longitud < long_max ? longitud : long_max - 1);
	Cadena.copy(cadena, longitud);
	cadena[longitud] = '\0';
}

void Contacto::establecerTelefono(const string& Telefono) {
	copiar_cadena(Telefono, telefono, 15);
}

string Contacto::obtenerNombre() const {
	return nombre;
}

void Contacto::establecerNombre(const string& Nombre) {
	copiar_cadena(Nombre, nombre, 50);
}

void Contacto::establecerId(const int Id) {
	id = Id;
}

int Contacto::obtenerId() const {
	return id;
}