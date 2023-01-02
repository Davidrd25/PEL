#include <iostream>
using namespace std;


int main(){

double a,b,c,d,resultado=0;

cout<<"Introduzca el valor de a: ";
cin>>a;
cout<<"Introduzca el valor de b: ";
cin>>b;
cout<<"Introduzca el valor de c: ";
cin>>c;
cout<<"Introduzca el valor de d: ";
cin>>d;

resultado = ((a+b)/(c+d));

cout.precision(2);
cout<<"El resulado obtenido es: "<<resultado<<endl;

return 0;

}