#include <iostream>
using namespace std;

int main(){

   int filas,columnas;
   int matriz1[filas][columnas];
   int matriz2[filas][columnas];
   int suma[filas][columnas];

    cout<<"Que numero de filas tendra: ";
    cin>>filas;
    cout<<"Que numero de columnas tendra: ";
    cin>>columnas;

    cout<<"Ingrese los valores de la matriz 1: "<<endl;
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			cout<<"fila: "<<i<<"columna: "<<j<<": ";
			cin>>matriz1[i][j];
		}
	}

    cout<<"Ingrese los valores de la matriz 2: "<<endl;
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			cout<<"fila: "<<i<<"columna: "<<j<<": ";
			cin>>matriz2[i][j];
		}
	}

    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            suma[i][j]=matriz1[i][j]+matriz2[i][j];
        }
    }

    cout<<"La suma de ambas matrcies es: "<<endl;
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            cout<<suma[i][j];
        }
        cout<<endl;
    }

    return 0;
}