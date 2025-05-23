#include "C3.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    Interpret JSON;

    JSON.getDatos().setData(1.3);
    JSON.getDatos().setData(2.1);
    JSON.getDatos().setData(3.2);
    JSON.getDatos().setData(string("Que"));
    JSON.getDatos().setData(string("Tal"));
    JSON.getDatos().setData(string("?"));
    JSON.getDatos().setData(vector<int>{1, 2});
    JSON.getDatos().setData(vector<int>{3, 8});
    JSON.imprimir();

    return 0;
}
