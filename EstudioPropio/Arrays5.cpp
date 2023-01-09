#include <iostream>
using namespace std;

int main(){

	int array [100],n,mayor=0;
	
	cout<<"Introduzca un array de numeros: ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<"Introduzca un numero: ";
		cin>>array[i]; //Guardo los elementos del vector

	if(array[i]>mayor){
		mayor = array[i];
		}
	}

	cout<<"El mayor elemento del array es: "<<mayor;

	return 0;	
}