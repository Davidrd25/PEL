#include <iostream>
using namespace std;


struct Persona{
	char nombre[20];
	int edad;
}persona1;


int main(){

	cout<<"Introduzca su nombre: ";
	cin.getline(persona1.nombre,20,'\n');
	cout<<"Introduzca su edad: ";
    cin>>persona1.edad;

    cout<<"Imprimiendo datos:"<<endl;
    cout<<"Nombre: "<<persona1.nombre<<endl;
    cout<<"Edad: "<<persona1.edad<<endl;

	return 0;
}