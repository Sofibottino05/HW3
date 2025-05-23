#include <iostream>
#include <memory>
#include <fstream>
#include<vector>

using namespace std;    


class Vectores{
    vector<double> doubles;
    vector<string> strings;
    vector<vector<int>> ints;
public:
    template<typename T>   //uso template para ingresar un tipo de dato, y if constexpr para evaluar en tiempo de compilacion que tipo de variable es la ingresada.
    void setData(const T& dato) {
        if constexpr (is_same_v<T,double>){
            doubles.push_back(dato);
        }
        if constexpr (is_same_v<T,string>){
            strings.push_back(dato);
        }
        if constexpr (is_same_v<T,vector<int>>){
            ints.push_back(dato);
        }
    }

    const vector<double>& getDoubles() const { return doubles; } //getters
    const vector<string>& getPalabras() const { return strings; }
    const vector<vector<int>>& getListas() const { return ints; }

};

class Interpret{

    Vectores datos; //instancio la clase Vectores
    public:

    Vectores& getDatos(){return datos;} //printeo en formato JSON los datos de tipo double
    void imprimir(){
        cout << "{\n"<<"  \"vec_doubles\": [";
        auto& doubles = datos.getDoubles();
        for (size_t i = 0; i<doubles.size();i++){
            cout<<doubles[i];
            if (i != doubles.size() - 1) cout << ", ";
        }
        cout<<"],\n";

        cout << "{\n"<<"  \"palabras\": ["; //printeo en formato JSON los datos de tipo double
        auto& strings = datos.getPalabras();
        for (size_t i = 0; i<strings.size();i++){
            cout<<strings[i];
            if (i != strings.size() - 1) cout << ", ";
        }
        cout<<"],\n";

        cout <<"{\n"<< "  \"listas\": [\n"; //printeo en formato JSON los datos de tipo listas
        const auto& listas = datos.getListas();
        for (size_t i = 0; i < listas.size(); ++i) {
            cout << "    [";
            for (size_t j = 0; j < listas[i].size(); ++j) {
                cout << listas[i][j];
                if (j != listas[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if (i != listas.size() - 1) cout << ",\n";
            else cout << "\n";
        }
        cout << "  ]\n";
        cout << "}\n";
    }
};



