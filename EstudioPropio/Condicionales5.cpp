#include <iostream>
using namespace std;


int main (){

char letra;

cout<<"Introduzca una vocal mayuscula o miniscula: ";
cin>>letra;

switch(letra){
	case 'a':
	case 'e':
	case 'i':
	case 'o':	
	case 'u':
	cout<<"La vocal es miniscula";
	break;
	default:
	cout<<"NO es un vocal miniscula";
    break;
}
return 0;

}