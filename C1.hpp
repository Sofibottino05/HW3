#ifndef C1_HPP
#define C1_HPP

#include <iostream>
#include <memory>
#include <fstream>

using namespace std;

class IMediciones {
public:
    virtual void serializar(ofstream& out) const = 0; //declaracion de los metodos virtuales puros de la clase interfaz
    virtual void deserializar(ifstream& in) = 0; 
    virtual void imprimir() const = 0;
    virtual ~IMediciones() = default; //destructor virtual default de la clase abstracta
};

class MedicionBase : public IMediciones {
protected:
    unique_ptr<float> tiempoMedicion;

public:
    MedicionBase(); //contructor default, y con parametro tiempo.
    MedicionBase(float tiempo);
    MedicionBase& operator=(const MedicionBase& other); // hago sobrecarga del operador = para que se haga deep copy del objeto cuando hagamo uso del mismo.

    float getTiempo() const; //getter
    void imprimir() const override;

    void serializar(ofstream& out) const override; //hago override de los metodos serializar y deserializar de la clase abstracta.
    void deserializar(ifstream& in) override;
};

class Presion : public MedicionBase {
public:
    float presionEstatica;  
    float presionDinamica;

    Presion();// constructores default y con parametros.
    Presion(float pe, float pd, float tiempo);
    Presion(const Presion& other);
    Presion& operator=(const Presion& other);

    void imprimir() const override;

    void serializar(ofstream& out) const override;//hago override de los metodos serializar y deserializar de la clase abstracta.
    void deserializar(ifstream& in) override;
};

class Posicion : public MedicionBase {
public:
    float latitud;
    float longitud;
    float altitud;

    Posicion(); // constructores default y con parametros.
    Posicion(float lat, float lon, float alt, float tiempo);
    Posicion(const Posicion& other);
    Posicion& operator=(const Posicion& other);

    void imprimir() const override;

    void serializar(ofstream& out) const override; //hago override de los metodos serializar y deserializar de la clase abstracta.
    void deserializar(ifstream& in) override;
};

class SaveFlightData {
private:
    Posicion posicion; //instancias de Posicion y Presion
    Presion presion;

public:
    SaveFlightData(const Posicion& pos, const Presion& pres); // constructor con parametros.
    void serializar(ofstream& out) const; 
    void deserializar(ifstream& in);
    void imprimir() const;
};

#endif
