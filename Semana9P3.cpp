#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Contacto.h"
#include "Funcion.h"
using namespace std;

void escrituraTexto() {
	ofstream archivoClientesSalida("clientes.txt", ios::out);
	if (!archivoClientesSalida) {
		cerr << "No se pudo abrir el archivo\n";
		exit(EXIT_FAILURE);
	}
	cout << "Escriba la cuenta, nombre y saldo.\nEscriba fin de archivo para terminar la entrada.\n?";
	int cuenta;
	string nombre;
	double saldo;
	while (cin >> cuenta >> nombre >> saldo) {
		archivoClientesSalida << cuenta << ' ' << nombre << ' ' << saldo << endl;
		cout << "? ";
	}
}

void lecturaDeTexto() {
	ifstream archivoClientesEntrada("clientes.txt", ios::in);
	if (!archivoClientesEntrada) {
		cerr << "No se pudo abrir el archivo\n";
		exit(EXIT_FAILURE);
	}
	int cuenta;
	string nombre;
	double saldo;
	cout << left << setw(10) << "Cuenta" << setw(13) << "Nombre" << "Saldo" << endl << fixed << showpoint;
	while (archivoClientesEntrada >> cuenta >> nombre >> saldo) {
		cout << left << setw(10) << cuenta << setw(13) << nombre << setw(7) << setprecision(2) << right << saldo << endl;
	}
}

int main() {
	fstream fcont0("contactos.dat", ios::out);
	fcont0.close();
	fstream fcont("contactos.dat", ios::in | ios::out | ios::binary);
	Funcion objFuncion(fcont);
	objFuncion.escribir_o_leer(true);
	cout << "ANTES:" << endl;
	objFuncion.escribir_o_leer(false);
	cout << endl << "CAMBIOS:" << endl;
	objFuncion.cambios();
	cout << endl << "DESPUES:" << endl;
	objFuncion.escribir_o_leer(false);
	fcont.close();
}