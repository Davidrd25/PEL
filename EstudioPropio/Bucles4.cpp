#include <iostream>
using namespace std;

int main(){

    int numero,contador=0;

    do{
        cout<<"Introduzca un numero: ";
        cin>>numero;
        if(numero>0){
            contador+=numero;
        }
    } while(numero<20 || numero>30 && numero!=0) ;

    cout<<"La suma es: "<<contador<<endl;

    return 0;
}