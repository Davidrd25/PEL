//Crea una lista enlazada de elementos que almacene como dato números enteros. Debe contener al menos 5 números enteros.

#include <iostream>
using namespace std;


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
    objLista->insertar(4);
    objLista->insertar(3);
    objLista->insertar(2);
    objLista->insertar(1);
    objLista->insertar(0);

    for(int i = 0; i<objLista->size(); ++i){
        cout<< objLista->mostrar(i) << endl;
    }
   

    return 0;
};