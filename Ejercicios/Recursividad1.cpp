#include <iostream>
using namespace std;

int sumarDatos(int n){

    if (n==1){
        return 1;
    }

    return n + sumarDatos(n-1);
}

int main (){

    int n = 0;

    cout << "Ingrese la cantidad de datos a sumar: ";
    cin >> n;
    cout << "El resultado de la suma es " << sumarDatos(n);

    return 0;
};