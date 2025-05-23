#include "C2.cpp"
#include <iostream>
#include <iomanip>
#include <vector>

int main(){

    Punto punto(8.4,3.5);
    Circulo circulo(3.4,2.5,4.5);
    Elipse elipse(3.2,6.7,9.2);
    Rectangulo rectangulo(8.6,5.3,8.3,1.9);

    float ac = ProcesadorFigura<Circulo>::calcularArea(circulo);
    float ae = ProcesadorFigura<Elipse>::calcularArea(elipse);
    float ar = ProcesadorFigura<Rectangulo>::calcularArea(rectangulo);

    cout<<"Aerea de circunferencia con radio "<< circulo.getRadio() << ": "<<  ac;
    cout<<"\nAerea de elipse con lado A de "<< elipse.getA() << "cm y lado b de "<<  elipse.getB()<< "cm, con area de "<<ae<<" cm^2";
    cout<<"\nAerea de rectangulo con lado de "<< rectangulo.getAncho() << "cm, y largo de "<< rectangulo.getLargo()<< "cm, con area de "<< ar<<" cm^2\n";

}