/*
Escribe un programa que lea de la entrada estandar los siguientes datos de una persona:

	Edad: dato de tipo entero
	Sexo: dato de tipo caracter
	Altura en metros: dato de tipo real

Tras leer los datos, el proggrama debe mantenerlos en la salida estandar
*/

#include <iostream>

using namespace std;


int main(){
	
	int edad;
	char sexo [10];
	double altura;

	cout<<"Ingrese la edad de la persona: ";
	cin >>edad;
	cout<<"Ingrese el sexo de la persona: ";
	cin >>sexo;
	cout<<"Ingrese la altura de la persona: ";
	cin >>altura;
	
	cout<<"La edad de la persona es: " <<edad<<endl;
	cout<<"El sexo de la persona es: " <<sexo<<endl;
	cout<<"La altura de la persona es: " <<altura<< " en metros"<<endl;
	
	return 0;
}