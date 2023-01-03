/*
Un programa que lea de entrada estandar numeros hasta que 
se introduzca un 0. En ese momento el programa debe terminar
y mostrar en pantalla el numero de valores mayores
que cero leidos
*/

#include <iostream>
using namespace std;

int main(){

int numero,contador=0;

do{
    cout<<"Introduzca un numero: ";
    cin>>numero;
    
    if(numero>0){
        contador++;
    }
    }while(numero!=0);  
        cout << "Ha introducido " << contador << " numeros mayores que cero" << endl;
        
}