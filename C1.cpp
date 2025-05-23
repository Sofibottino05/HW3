#include "C1.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

MedicionBase::MedicionBase() : tiempoMedicion(make_unique<float>(0.0f)) {}  //constructores

MedicionBase::MedicionBase(float tiempo) : tiempoMedicion(make_unique<float>(tiempo)) {}

MedicionBase& MedicionBase::operator=(const MedicionBase& other) { //sobrecarga del operador = para hacer la copia, con el uso de deep copy.
    if (this != &other) {
        if (other.tiempoMedicion)
            tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
        else
            tiempoMedicion.reset();
    }
    return *this;
}

float MedicionBase::getTiempo() const {//getter
    return *tiempoMedicion;
}

void MedicionBase::imprimir() const {
    cout << "Tiempo: " << *tiempoMedicion << " s" << endl;
}

void MedicionBase::serializar(ofstream& out) const { //serializar MedicionBase
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void MedicionBase::deserializar(ifstream& in) { //deserializar MedicionBase
    float tiempo;
    in.read(reinterpret_cast<char*>(&tiempo), sizeof(float));
    tiempoMedicion = make_unique<float>(tiempo);
}

// Presion
Presion::Presion() : presionEstatica(0.0f), presionDinamica(0.0f) {} //constructor generico, y con parametros

Presion::Presion(float pe, float pd, float tiempo)
    : MedicionBase(tiempo), presionEstatica(pe), presionDinamica(pd) {}

Presion& Presion::operator=(const Presion& other) {   //sobrecarga del operador = para hacer la copia, con el uso de deep copy.
    if (this != &other) {
        MedicionBase::operator=(other);
        presionEstatica = other.presionEstatica;
        presionDinamica = other.presionDinamica;
    }
    return *this;
}

void Presion::serializar(ofstream& out) const { //serializo usando el metodo serializar de la clase base MedicionBae, y serializando los atributos de Presion.
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(ifstream& in) {  //deserializo usando el metodo deserializar de la clase base MedicionBae, y serializando los atributos de Presion.
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::imprimir() const {
    MedicionBase::imprimir();
    cout << "Presión Estática: " << presionEstatica << " Pa" << endl;
    cout << "Presión Dinámica: " << presionDinamica << " Pa" << endl;
}

// Posicion
Posicion::Posicion() : latitud(0.0f), longitud(0.0f), altitud(0.0f) {}

Posicion::Posicion(float lat, float lon, float alt, float tiempo)
    : MedicionBase(tiempo), latitud(lat), longitud(lon), altitud(alt) {}

Posicion::Posicion(const Posicion& other)
    : MedicionBase(other), latitud(other.latitud), longitud(other.longitud), altitud(other.altitud) {}

Posicion& Posicion::operator=(const Posicion& other) {
    if (this != &other) {
        MedicionBase::operator=(other);
        latitud = other.latitud;
        longitud = other.longitud;
        altitud = other.altitud;
    }
    return *this;
}

void Posicion::serializar(ofstream& out) const {  //serializo usando el metodo serializar de la clase base MedicionBae, y serializando los atributos de Posicion.
   
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion::deserializar(ifstream& in) { //deserializo usando el metodo deserializar de la clase base MedicionBae, y serializando los atributos de Posicion.
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion::imprimir() const {
    MedicionBase::imprimir();
    cout << "Latitud: " << latitud << ", Longitud: " << longitud << ", Altitud: " << altitud << " m" << endl;
}

// SaveFlightData
SaveFlightData::SaveFlightData(const Posicion& pos, const Presion& pres)
    : posicion(pos), presion(pres) {}

void SaveFlightData::serializar(ofstream& out) const {//serializo usando el metodo serializar de ambos objetos presion y posicion.
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in) {//deserializo usando el metodo deserializar de ambos objetos presion y posicion.
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const {
    cout << "===== Datos del Vuelo =====" << endl;
    cout << "-- Posición --" << endl;
    posicion.imprimir();
    cout << "-- Presión --" << endl;
    presion.imprimir();
}
