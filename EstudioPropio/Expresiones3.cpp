// Created: 2019-10-16 11:10:00
#include <iostream>
using namespace std;


int main(){

double a,b,c,d,e,f,resultado=0;

cout<<"Introduzca el valor de a: ";
cin>>a;
cout<<"Introduzca el valor de b: ";
cin>>b;
cout<<"Introduzca el valor de c: ";
cin>>c;
cout<<"Introduzca el valor de d: ";
cin>>d;
cout<<"Introduzca el valor de e: ";
cin>>e;
cout<<"Introduzca el valor de f: ";
cin>>f;


resultado = ((a+(b/c))/(d+(e/f)));

cout.precision(2);
cout<<"El resulado obtenido es: "<<resultado<<endl;

return 0;

}