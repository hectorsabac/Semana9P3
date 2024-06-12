#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Contacto.h"
using namespace std;

void leer_el_3(fstream& fcont, Contacto& cont) {
    fcont.seekp(3 * sizeof(Contacto));
    fcont.read(reinterpret_cast<char*>(&cont), sizeof(Contacto));
    cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
}

void cambios(fstream& fcont) {
    Contacto cont;
    leer_el_3(fcont, cont);
    //escribir_el_3(fcont, cont); este no lo dio el inge
    leer_el_3(fcont, cont);
}

void escribir_o_leer(fstream& fcont, bool Escribir) {
    for (int i = 0; i < 6; i++) {
        if (Escribir) {
            Contacto cont("FALTA TELEFONO", "Nombre " + to_string(i), i);
            fcont.write(reinterpret_cast <const char*> (&cont), sizeof(Contacto));
        }
        else {
            Contacto cont;
            fcont.seekp(i * sizeof(Contacto));
            fcont.read(reinterpret_cast <char*>(&cont), sizeof(Contacto));
            cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
        }

    }
}

void miEscribirOLeer(fstream& file, bool escribir) {
    if (escribir) {
        for (int i = 0; i < 6; i++) {
            Contacto contacto("No Phone", "Name " + to_string(i), i);
            file.write(reinterpret_cast<char*>(&contacto), sizeof(Contacto));
        }
    }
    else {
        file.seekg(0);
        while (true) {
            Contacto contacto;
            file.read(reinterpret_cast<char*>(&contacto), sizeof(Contacto));
            if (file.eof()) {
                break;
            }
            if (file.fail()) {
                cerr << "Cagaste papi\n";
                break;
            }
            cout << contacto.obtenerId() << ":" << contacto.obtenerNombre() << endl;
        }
    }
}

void dix_jun() {
    fstream fcont0("contactos.dat", ios::out);
    fcont0.close();
    fstream fcont("contactos.dat", ios::in | ios::out | ios::binary);
    escribir_o_leer(fcont, true);
    cout << "ANTES: " << endl;
    escribir_o_leer(fcont, false);
    cout << endl << "CAMBIOS:" << endl;
    cambios(fcont);
    cout << endl << "DESPUES:" << endl;
    escribir_o_leer(fcont, false);
    fcont.close();
}

void escribir() {
    ofstream archivoClientesSalida("clientes.txt", ios::out);
    if (!archivoClientesSalida) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Escriba la cuenta, nombre y saldo" << endl
        << "Escriba fin de archivo para terminar la entrada.\n? ";
    int cuenta;
    string nombre;
    double saldo;
    while (cin >> cuenta >> nombre >> saldo) {
        archivoClientesSalida << cuenta << ' ' << nombre << ' ' << saldo << endl;
        cout << "?";
    }
}

void leer() {
    ifstream archivoClientesEntrada("clientes.txt", ios::in);
    if (!archivoClientesEntrada) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    int cuenta;
    string nombre;
    double saldo;
    cout << left << setw(10) << "Cuenta" << setw(13)
        << "Nombre" << "Saldo" << endl << fixed << showpoint;
    while (archivoClientesEntrada >> cuenta >> nombre >> saldo)
        cout << left << setw(10) << cuenta << setw(13) << nombre
        << setw(7) << setprecision(2) << right << saldo << endl;
}


class Persona {
    int edad;
    string nombre, apellido;
    double salario;
public:
    Persona(int edad = 0, string nombre = "", string apellido = "", double salario = 0) {
        this->edad = edad;
        this->nombre = nombre;
        this->apellido = apellido;
        this->salario = salario;
    }

    void print() {
        cout << "Edad: " << edad << "\tNombre: " << nombre << "\tApellido: " << apellido << "\tSalario: " << salario << endl;
    }

    void escribirEn(fstream& file) {
        file.write(reinterpret_cast<char*>(this), sizeof(Persona));
        cout << "Escrito en el documento!\n";
    }
};

void leerDe(fstream& file) {
    cout << "Lectura: " << endl;
    Persona persona;
    file.seekg(0, ios::end);
    int size = file.tellg();
    file.seekp(0);

    while (file.tellg() < size) {
        file.read(reinterpret_cast<char*>(&persona), sizeof(Persona));
        if (file.fail()) {
            cerr << "Error al leer del archivo\n";
            break;
        }
        persona.print();
    }
}


int main() {
    escribir(); 
    leer(); 
    dix_jun();
    /*fstream file("newDataBase.db", ios::in | ios::out | ios::binary | ios::trunc);
    miEscribirOLeer(file, true);
    file.flush();
    file.seekg(0);
    miEscribirOLeer(file, false);*/
}