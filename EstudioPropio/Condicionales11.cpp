#include <iostream>
using namespace std;

int main(){

int saldoInicial=1000;
int opcion,dinero,saldoFinal;


cout<<"\t Bienvenido a su cajero automatico"<<endl;
cout<<"1. Ingresar dinero en cuenta"<<endl;
cout<<"2. Extraer dinero de su cuenta"<<endl;
cout<<"3. Salir"<<endl;
cout<<"Opcion: ";
cin>>opcion;

switch(opcion){

	case 1:
		cout<<"Cuanto dinero desea ingresar? ";
		cin>>dinero;
		
		saldoFinal = dinero +saldoInicial;
		
		cout<<"Ahora tiene "<<saldoFinal<<" euros en su cuenta";
		break;
	case 2:
		cout<<"Cuanto dinero desea retirar? ";
		cin>>dinero;
		
		if (dinero>saldoInicial){
			cout<<"No tiene esa cantidad de dinero";
		}else{
		saldoFinal = saldoInicial-dinero;
		
		cout<<"Ahora tiene "<<saldoFinal<<" euros en su cuenta";
		}
		break;
	case 3:
		break;

}
return 0;

}