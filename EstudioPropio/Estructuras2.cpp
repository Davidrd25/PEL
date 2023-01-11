/*
Hacer una estructura llamada corredor, en la cual se tendran los siguinetes
campo: Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asi
una categoria de competicion:
-Juvenil <= 18 años
-Senior <= 40 años
-Vetrerano > 40 años
Posteriormente imprimir todos los datos del corredor, incluida su categoria de
competicion.
*/

#include <iostream>
using namespace std;

struct corredor{
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
}corredores[2];

int main(){

	for(int i=0; i<2; i++){
		
		cout<<"Introduzca su nombre: ";
		cin.getline(corredores[i].nombre,20,'\n');
		cout<<"Introduzca su edad: ";
		cin>>corredores[i].edad;
        fflush(stdin);
		cout<<"Introduzca su sexo: ";
		cin.getline(corredores[i].sexo,10,'\n');
		cout<<"Introduzca su club: ";
		cin.getline(corredores[i].club,20,'\n');
        cout<<endl;
	}
	
	for(int i=0; i<2; i++){
		cout<<"Nombre: "<<corredores[i].nombre<<endl;
		cout<<"Edad: "<<corredores[i].edad<<endl;
		cout<<"Sexo: "<<corredores[i].sexo<<endl;
		cout<<"Club: "<<corredores[i].club<<endl;
		if(corredores[i].edad <= 18){
            cout<<"Categoria: Juvenil"<<endl;
        }else if (corredores[i].edad <= 40){
            cout<<"Categoria: Senior"<<endl;
        }else{
            cout<<"Categoria: Veterano"<<endl;
        }
	}

	return 0;

}