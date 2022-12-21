#include <iostream>
using namespace std;

/*
Dado un número entero positivo n, obtener la suma se los dísgitos de os que consta mediante dos algoritmos. Uno iterativo y otro recursivo.
*/

int sumarDatos(int n){

    if (n<10){
        return n;
    }else {
        
        return sumarDatos(n/10) +n%10;
    }
}

int main (){

    int n = 0;

    cout << "Ingrese el dato a sumar: ";
    cin >> n;
    cout << "El resultado de la suma  del dato es " << sumarDatos(n);

    return 0;
};