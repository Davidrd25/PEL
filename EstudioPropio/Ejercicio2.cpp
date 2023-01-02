/*
Escribe un programa que lea de la entrada estandar el precio de un producto y muestre de salida
estandar el precio del producto al aplicarle el IVA
*/

#include <iostream>

using namespace std;


int main(){

	double precio = 10;
	double IVA = 21;
	double precioIva;

	cout<<"El precio del producto es: "<<precio<<endl;
	
	precioIva = precio + precio*IVA/100;

	cout<<"El precio del producto con IVA es: "<<precioIva<<endl;


	return 0;
}