#pragma once
#include <string>
using namespace std;
class Contacto {
	int id;
	char nombre[50], telefono[15];
public:
	Contacto(const string & = "0000-0000", const string & = "", const int = 0);
	void establecerTelefono(const string&);
	string obtenerTelefono() const;
	void establecerNombre(const string&);
	string obtenerNombre() const;
	void establecerId(const int);
	int obtenerId() const;
};

