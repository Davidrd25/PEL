#include <iostream>
using namespace std;

int main (){

    double a,b,resultado=0;

    cout<<"Ingrese el valor de a: ";
    cin>>a;
    cout<<"Ingrese el valor de b: ";
    cin>>b;

    resultado = (a/b) + 1;

    cout.precision(2);
    cout<<"El resultado es: " <<resultado<<endl;

    return 0;
} 