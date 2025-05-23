#include "C1.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){

    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3); 
    Presion presion(101.3f, 5.8f, 6.1f);
    SaveFlightData datos(posicion,presion);

    ofstream Salida("vuelo.dat", ios::binary);
    if (!Salida) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return 1;
    }
    datos.serializar(Salida);
    Salida.close();
    SaveFlightData datosRecu({0, 0, 0, 0}, {0, 0, 0}); // inicializo el dummy con valores 0
    ifstream Entrada("vuelo.dat", ios::binary);
    if (!Entrada) {
        cerr << "No se pudo abrir el archivo para leer." << endl;
        return 1;
    }
    datosRecu.deserializar(Entrada);
    Entrada.close();
    //muestro los datos
    cout << "Objeto Original:" << endl;
    datos.imprimir();

    cout << "\nObjeto Recuperado:" << endl;
    datos.imprimir();

    return 0;




}