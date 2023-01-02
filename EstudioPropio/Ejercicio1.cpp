/*
Escribe un programa que lea de engrada esatndar dos numeros y muestre en la salida estandar su suma, resta, multiplicacion y division
*/

#include <iostream>
using namespace std;

int main (){

    double a, b, suma, resta, multiplicacion, division;

    cout << "Introduce el primer numero: ";
    cin >> a;
    cout << "Introduce el segundo numero: ";
    cin >> b;

    suma = a + b;
    resta = a - b;
    multiplicacion = a * b;
    division = a / b;

    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicacion es: " << multiplicacion << endl;
    cout << "La division es: " << division << endl;
    

    return 0;
}