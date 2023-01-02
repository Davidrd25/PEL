#include <iostream>
#include <math.h>
using namespace std;
int main(){

double a,b,aux1,aux2,h=0;

cout<<"Introduzca el valor de a: ";
cin>>a;
cout<<"Introduzca el valor de b: ";
cin>>b;

aux1=pow(a,2);
aux2=pow(b,2);

h = sqrt(aux1+aux2);

cout<<"La hipotenusa es: "<<h;

return 0;

}

