#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Contacto.h"
using namespace std;

class Funcion{
	fstream &fcont;
public:
	Funcion(fstream& file);
	~Funcion();
	void escribir_o_leer(bool escribir);
	void leer_el_3(Contacto& cont);
	void escribir_el_3(Contacto& cont);
	void cambios();
};

