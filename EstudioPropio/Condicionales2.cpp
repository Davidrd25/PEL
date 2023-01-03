#include <iostream>
using namespace std;

int main(){

int num,dato=5;

cout<<"Introduce un numero entre el 1-5:";
cin>>num;


if (num>6){

	cout<<"El numero introducido no se encuentr en el requerido";

}else{

	switch(num){

	case 1: 
		cout<<"Es el numero 1";
		break;
	case 2: 
		cout<<"Es el numero 2";
		break;
	case 3: 
		cout<<"Es el numero 3";
		break;
	case 4: 
		cout<<"Es el numero 4";
		break;
	case 5: 
		cout<<"Es el numero 5";
		break;
	}
}

return 0;

}
