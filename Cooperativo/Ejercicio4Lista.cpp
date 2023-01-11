/*
Realiza un programa para crear una lista de números aleatorios. Los nuevos
números deben insertarse en el centro de la lista (o el punto medio de los
elementos de la misma). Una vez creada se ha de recorrer mostrando
únicamente los números impares.
Detalles:
• Deben meterse los números aleatorios por el teclado del usuario.
• Para terminar de crear la lista, se introducirá el valor reservado -1.
*/

#include <iostream>
using namespace std;

//Crear una variable donde almacene los numeros que introduzca el usuario
class dato{
    int numero;
    dato(int num){
        numero = num;
    }
};
template <typename T> class listaPEL{
    protected:    
    class Nodo{
        public: 
            T elemento;
            Nodo* siguiente;
            Nodo(T e){
                elemento = e;
                siguiente = 0;
            }
    };
    Nodo* primero;
    public:
    listaPEL(){
        primero = 0;
    }
    void insertar(T e){
        Nodo* nuevoNodo = new Nodo(e);
        nuevoNodo->siguiente = primero;
        primero = nuevoNodo;
    }
    int size(){
        int cont = 0;
        bool existe_enlace = true; // si hay un enlace(puntero) significa que hay un nuevo elemetno cuando llegue al moento en el que no existe 
                                   //ahi es donde hay q añadir el nuevo elemetno por lo tanto hay que salir de bucle
        Nodo* aux = primero;       
        while(existe_enlace == true){
            if(aux-> siguiente != 0){
                aux = aux->siguiente;//el valor de aux es el varlor del puntero
                ++cont;
            }else{   
                existe_enlace = false;
            }
        }
        if(cont != 0){
            return cont + 1;
        }
        return cont + 1;
    }

    void insertar_pos(T e, int pos){
        
        if(pos > size()){
            std::cout << "No se puede insertar en dicha posicion";
        }else{
            Nodo* aux = primero;
            for (int i = 0; i < pos; ++i){
                aux = aux->siguiente;//el nodo de la posicion que queremos insertar es decir si qwueremos insertar en la pos 5 guarda el nodo 4 que referencia al nodo5
            }
            Nodo* nuevoNodo = new Nodo(e);
            nuevoNodo->siguiente = aux->siguiente;//el puntero del nuevo elemento  sera al que apunte el puntero actual
            aux->siguiente = nuevoNodo;// el puntero actual ahora debe apuntar al nuevo elemento
            
        }

    }

    T mostrar(int pos){
        if (pos > size()){
            cout << "no se puede mostrar en dicha posicion: "  << pos << endl;
        }else{
            Nodo* aux = primero;
            for(int i = 0; i< pos; ++i){
                aux = aux->siguiente;
            }
            return aux->elemento;
        }
    }

};

 int main(int, char**){

    int numero;
    listaPEL<int>* objLista = new listaPEL<int>();
    objLista->insertar(0);
    cout<<"Introduce una serie de numeros aleatorios. Para terminar la serie introduce (-1): ";
    cin>>numero;

    //Mientras el usuario no introduzca -1, se seguirá pidiendo números
    do{
        int mitad = objLista->size()/2;
        objLista->insertar_pos(numero, mitad);
        cout<<"Introduce una serie de numeros aleatorios. Para terminar la serie introduce (-1): ";
        cin>>numero;
    } while (numero != -1);

    //Recorrer la lista y mostrar los números impares
    for(int i=0; i<objLista->size();i++){
        if(objLista->mostrar(i) % 2 != 0){
            cout << objLista->mostrar(i) << endl;
        }

    }
    return 0;
};