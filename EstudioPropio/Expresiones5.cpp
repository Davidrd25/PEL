#include <iostream>
using namespace std;


int main(){

double nota1,nota2,nota3,nota4,notaFinal=0;
int alumno=4;

cout<<"Introduzca el valor de nota1: ";
cin>>nota1;
cout<<"Introduzca el valor de nota2: ";
cin>>nota2;
cout<<"Introduzca el valor de nota3: ";
cin>>nota3;
cout<<"Introduzca el valor de nota4: ";
cin>>nota4;

notaFinal=(nota1+nota2+nota3+nota4)/alumno;

cout.precision(2);
cout<<"La nota media final es: "<<notaFinal;

return 0;

}

