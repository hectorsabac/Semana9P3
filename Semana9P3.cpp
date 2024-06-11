#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void escritura() {
    ofstream archivosClientesSalida("clientes.txt", ios::out);
    if (!archivosClientesSalida) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Escriba la cuenta, nombre y saldo." << endl
        << "Escriba fin de archivo para terminar la entrada.\n? ";
    int cuenta; string nombre; double saldo;
    while (cin >> cuenta >> nombre >> saldo) {
        archivosClientesSalida << cuenta << ' ' << nombre << ' ' << saldo << endl;
        cout << "?";
    }
}

void lectura() {
    ifstream archivoClientesEntrada("clientes.txt", ios::in);
    if (!archivoClientesEntrada) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    int cuenta; string nombre; double saldo;
    cout << left << setw(10) << "Cuenta" << setw(13)
        << "Nombre" << "Saldo" << endl << fixed << showpoint;
    while (archivoClientesEntrada >> cuenta >> nombre >> saldo) {
        cout << left << setw(10) << cuenta << setw(13) << nombre << setw(7) << setprecision(2) << right << saldo << endl;
    }
}

int main() {
    escritura();
    lectura();
}