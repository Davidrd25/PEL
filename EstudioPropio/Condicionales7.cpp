#include <iostream>
using namespace std;


int main (){

int edad;

cout<<"Introduzca una edad entre 18-25: ";
cin>>edad;

if (edad<18 || edad>25){
	cout<<"La edad introducida esta fuera del rango";
} else {
	cout<<"La edad se encuentra dentro del rango";
}
return 0;

}