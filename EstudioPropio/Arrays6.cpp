/*
Escribe un programa que defina un vector de numeros y calculesi existe algun numero en el vector cuyo valor equivale a la suma del resto de numeros
del vector
*/

#include <iostream>
using namespace std;

int main(){

    int array [100],n,suma=0,aux=0;

    cout<<"Introduzca un array de numeros: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"Introduzca un numero: ";
        cin>>array[i]; //Guardo los elementos del vector
        suma = suma + array[i];
    }

    for(int i=0; i<n; i++){
        aux = suma - array[i];
        if(aux == array[i]){
            cout<<"El numero "<<array[i]<<" es igual a la suma del resto de numeros del vector";
        }
    }

    return 0;	

}