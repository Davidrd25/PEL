#include <iostream>
using namespace std;

int main(){

	int array [100],n;
	
	cout<<"Introduzca un array de numeros: ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<"Introduzca un numero: ";
		cin>>array[i]; //Guardo los elementos del vector
	}
	//Mostramos los elementos con sus indices asociados

	for(int i=0; i<n; i++){
		cout<<i<<" -> "<<array[i]<<endl;
		
	}



	return 0;	
}