#include <iostream>
using namespace std;


int main (){

int num1,num2,num3,num4;

cout<<"Introduzca el valor del num1: ";
cin>>num1;
cout<<"Introduzca el valor del num2: ";
cin>>num2;
cout<<"Introduzca el valor del num3: ";
cin>>num3;
cout<<"Introduzca el valor del num4: ";
cin>>num4;

if (num4==num1){
	cout<<"El num4 es igual al num1";
} else if (num4==num2){
	cout<<"El num4 es igual al num2";
} else if (num4==num3){
	cout<<"El num4 es igual al num3";
} else{
	cout<<"El num4 no es igual a ninguno de los anteriores";
}
return 0;

}