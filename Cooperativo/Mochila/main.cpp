#include <iostream>
#include <vector>

using namespace std;
/**
 * struct mochila{
    int obj_int;
    string obj_str;
    bool boolean;
};

vector <mochila> vMochila = {};
int contador=0;

template <typename T> 
void meterObjeto(T objeto){

    vMochila.push_back(T);
    contador++;

}

void eliminarObjeto(){

}

void mostrarObjeto(){

}

void menu(){

    cout << "\n    MENU DE ALMACENAMIENTO DE OBJETOS";
	cout << "\n -------------------------------------";
	cout << "\n1. Almacenar nuevo obejto ....(Pulsa1)";
	cout << "\n2. Eliminar obejto ...........(Pulsa2)";
};

int main(){
	
	int opcion;
		
		do{
		menu();
		cin >> opcion;
		if( cin.fail() || cin.bad() ){
            opcion = 0;
            cin.clear();
            cin.ignore( '\n', 80 );
        }
        template <typename T> 
        T obj;
		switch (opcion){
			
			case 1: 
				meterObjeto(cin >> obj);
				break;
			case 2:
				eliminarObjeto();
				break;
			default:
				cout << "OPCION NO VALIDA\n\n";
				break;
			}
		}while (opcion!= 2);
		
}
*/
template <typename T> class Mochila{
    public:
    vector<T> objetos;
 
    void mostrarVector(){
        for(int i = 0;i < objetos.size();i++){
            cout<<i<<"->"<<objetos.at(i)<<endl;
        }
}
};


int main(int, char**){
    int opcion = -1;
    bool salir = false;
    int eleccion;
    int posicion;
    string texto;
    Mochila<int> intMochila;
    Mochila<string> StringMochila;
    Mochila<float> FloatMochila;
    Mochila<double> DoubleMochila;
    
    while(!salir){
        cout << "1) Int " << endl;
        cout << "2) String" << endl;
        cout << "3) Float" << endl;
        cout << "4) Double" << endl;
        cout << "5) Salir" << endl;
        cout<< " Opcion:";
        cin>>opcion;
        switch(opcion){
        case 1:
            cout<<"agregar[1] o eliminar[2]: ";
            cin>>eleccion;
            int number,posicion;
            if(eleccion == 1){
            intMochila.mostrarVector();
            cout<<"Introduce el numero:";
            cin>>number;
            intMochila.objetos.push_back(number);
            }else{
                intMochila.mostrarVector();
                cout<<"Introduce la posicion a eliminar:";
                cin>>posicion;
                intMochila.objetos.erase(intMochila.objetos.begin() + posicion);
            };
            break;
        case 2:
            cout<<"agregar[1] o eliminar[2]: ";
            cin>>eleccion;
            if(eleccion == 1){
            StringMochila.mostrarVector();
            cout<<"Introduce el texto:";
            cin>>texto;
            StringMochila.objetos.push_back(texto);
            }else{
                StringMochila.mostrarVector();
                cout<<"Introduce la posicion a eliminar:";
                cin>>posicion;
                StringMochila.objetos.erase(StringMochila.objetos.begin() + posicion);
            };
            break;
        case 3:
            cout<<"agregar[1] o eliminar[2]: ";
            cin>>eleccion;
            float flotante;
            if(eleccion == 1){
            FloatMochila.mostrarVector();
            cout<<"Introduce el numero:";
            cin>>flotante;
            FloatMochila.objetos.push_back(flotante);
            }else{
                FloatMochila.mostrarVector();
                cout<<"Introduce la posicion a borrar:";
                cin>>posicion;
                FloatMochila.objetos.erase(FloatMochila.objetos.begin() + posicion);
            };
            break;

        case 4:
            cout<<"agregar[1] o eliminar[2]:";
            cin>>eleccion;
            double numero;
            if(eleccion == 1){
            DoubleMochila.mostrarVector();
            cout<<"Introduce el numero:";
            cin>>flotante;
            DoubleMochila.objetos.push_back(numero);
            }else{
                DoubleMochila.mostrarVector();
                cout<<"Introduce la posicion a eliminar:";
                cin>>posicion;
                DoubleMochila.objetos.erase(DoubleMochila.objetos.begin() + posicion);
            };
            break;
        case 5:
            cout<<"Saliendo...";
            exit(EXIT_SUCCESS);
            break;
        default:
            cout << "Numero incorrecto";
            break;
        };

    };
}