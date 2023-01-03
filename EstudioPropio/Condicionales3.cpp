#include <iostream>
using namespace std;

//Escribe un programa que lea dos numeros y determine cual de ellos es el mayor

int main(){

int num1,num2;

cout<<"Introduce el primer numero: ";
cin>>num1;
cout<<"Introduce el segundo numero: ";
cin>>num2;


if (num1==num2){
    cout<<"Los numeros son iguales";
}else if(num1>num2){
	cout<<"El primer numero "<<num1<< " es mayor que el segundo numero "<<num2;
}else{
	cout<<"El segundo numero "<<num2<< " es mayor que el primer numero "<<num1;
}

return 0;
}