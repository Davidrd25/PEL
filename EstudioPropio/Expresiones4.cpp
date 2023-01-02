#include <iostream>
using namespace std;


int main(){

int a,b,aux;

cout<<"Introduzca el valor de a: ";
cin>>a;
cout<<"Introduzca el valor de b: ";
cin>>b;

aux=a;
a=b;
b=aux;

cout<<"El valor de a es: "<<a<<" y el valor de b es: "<<b;
return 0;

}
