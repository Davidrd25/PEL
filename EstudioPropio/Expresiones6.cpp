#include <iostream>
using namespace std;

/*
La calificacion final de un estudiante es la media ponderada de tres notas:
La nota de las practicas que cuenta un 30% del total, la nota teorica que cuenta
un 60% y la nota de participacion que cuenta un 10% restante. Escriba un programa
en c++ que lea la entrada estandar de las tres notas del alumno y escriba en la 
salida estandar su notafinal
*/

int main(){

double practica,teorica,participacion,notaFinal=0;

cout<<"Introduzca el valor de practica: ";
cin>>practica;
cout<<"Introduzca el valor de teorica: ";
cin>>teorica;
cout<<"Introduzca el valor de participacion: ";
cin>>participacion;

practica=practica*0.3;
teorica=teorica*0.6;
participacion=participacion*0.1;

notaFinal=practica+teorica+participacion;

cout<<"La nota media final es: "<<notaFinal;

return 0;

}
