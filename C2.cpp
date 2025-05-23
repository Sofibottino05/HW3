#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

class Punto{
    float x;  
    float y;
    public:

    Punto(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const{return x;}
    float getY() const{return y;}

    void setX(float X){x=X;}
    void setY(float Y){y=Y;}
};

class Circulo{
    Punto centro;
    float radio;
    public:

    Circulo(float x = 0, float y = 0, float r = 0) : centro(x,y), radio(r){}

    void setCentro(Punto p){centro = p;}
    void setRadio(float r){radio = r;}

    Punto getCentro()const{return centro;}
    float getRadio()const{return radio;}
};

class Elipse{
    Punto centro;
    float a;
    float b;
    public:

    Elipse(float x = 0, float y = 0, float A = 0, float B = 0) : centro(x,y), a(A), b(B){}

    void setCentro(Punto p){centro = p;}
    void setA(float A){a = A;}
    void setB(float B){b = B;}

    Punto getCentro()const{return centro;}
    float getA()const{return a;}
    float getB()const{return b;}
};

class Rectangulo{
    Punto verticeii; //vertice inferior izquierdo
    float ancho;
    float largo;
    public:

    Rectangulo(float x = 0, float y = 0, float a = 0, float b = 0) : verticeii(x,y), ancho(a), largo(b){}

    void setVerticeii(Punto p){verticeii = p;}
    void setAncho(float A){ancho = A;}
    void setLargo(float B){largo = B;}

    Punto getVerticeii()const{return verticeii;}
    float getAncho()const{return ancho;}
    float getLargo()const{return largo;}
};

template<typename T> //uso template para el uso especializado de la clase para cada tipo de figura. En este caso es generico ante cualquier tipo de figura que no este en los templates especificos a Circulo, Elipse o Rectangulo.
class ProcesadorFigura {
public:
    static void calcularArea(const T& figura) {
        cout<< "El tipo de figura que ingresaste no esta dentro de nuestra base de datos.\n";
    }
};

template<> //Template para Circulo
class ProcesadorFigura<Circulo> {  ///Calcula el area del objeto Circulo
public:
    static float calcularArea(const Circulo& c) {
        return static_cast<float>(M_PI) * c.getRadio() * c.getRadio();
    }
};

template<> //Template para Elipse
class ProcesadorFigura<Elipse> { ///Calcula el area del objeto Elipse
public:
    static float calcularArea(const Elipse& e) {
        return static_cast<float>(M_PI) * e.getA() * e.getB();
    }
};

template<> //Template para Rectangulo
class ProcesadorFigura<Rectangulo> {  ///Calcula el area del objeto Rectangulo
public:
    static float calcularArea(const Rectangulo& r) {
        return r.getAncho() * r.getLargo();
    }
};