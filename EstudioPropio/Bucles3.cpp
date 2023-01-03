#include <iostream>
using namespace std;

int main(){

int suma=0,cuadrado;

for(int i=1; i<=10;i++){

	cuadrado=i*i;
	cout<<cuadrado<<endl;
	suma = suma + cuadrado;
}

cout<<"La suma total de los cuadrados es: "<<suma;

	
return 0;

}