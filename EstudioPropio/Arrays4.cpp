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

	//Mostramos los elementos en el orden inverso
    for(int i=n-1; i>=0; i--){
        cout<<array[i]<<endl;
    }
		
}