#include <iostream>
using namespace std;

template <typename T> class Nodo
{
 private:
    T dato;
    Nodo<T>* enlace;
 
 public:
    Nodo(T d)
    {
        Nodo::dato = d;
        Nodo::enlace = 0;
    }
 public:
    Nodo(T p, Nodo<T>* n)
    {
    Nodo::dato = p;
    Nodo::enlace = n;
    }
    T datoNodo() const
    {
        return dato;
    }

    Nodo<T>* enlaceNodo() 
    {
        return enlace;
    }

    void ponerEnlace(Nodo<T>* sgte)
    {
        enlace = sgte;
    }
};

template <typename T> void recorremeEsta(Nodo<T>* pseudoLista)
{
    bool existe_enlace = true;
    while(existe_enlace == true){
        cout << pseudoLista->datoNodo() << endl;

        if(pseudoLista->enlaceNodo() == NULL){
            existe_enlace = false;
        }else{
            pseudoLista = pseudoLista->enlaceNodo();
        }
    }
}

//Funciones de insertar datos

template <typename T> void insertarCabezaLista(Nodo<T>* &datoNuevo, Nodo<T>* &pseudoLista){

    datoNuevo-> ponerEnlace(pseudoLista);
    pseudoLista = datoNuevo;

}

template <typename T> void insertarColaLista(Nodo<T>* &datoNuevo, Nodo<T>* &pseudoLista){

    bool nodoTerminal = false;
    Nodo<T>* aux =  pseudoLista;
    while (nodoTerminal == false){
        if (aux->enlaceNodo()==NULL){
            aux->ponerEnlace(datoNuevo);
            nodoTerminal = true;
        }else{
            aux =aux->enlaceNodo();
        }
    }
}

template <typename T> void insertarPosicion(Nodo<T>* &datoNuevo, int pos, Nodo<T>* &pseudoLista){
    
    int posicion = 0;
    bool salidaBucle = false;
    Nodo<T>* aux =  pseudoLista;
    while (salidaBucle == false){
        if (pos == posicion){
            datoNuevo->ponerEnlace(aux->enlaceNodo());
            aux->ponerEnlace(datoNuevo);
            salidaBucle=true;
        }else{
            if (aux->enlaceNodo() == NULL){
                salidaBucle = true;
            }else{
                ++posicion;
                aux = aux->enlaceNodo();
            }
        }
    }
}

int main(int, char**) 
{

Nodo <int>* n1 = new Nodo(1);
Nodo <int>* n2 = new Nodo(2);
Nodo <int>* n3 = new Nodo(3);


n1->ponerEnlace(n2);
n2->ponerEnlace(n3);

Nodo <int>* pseudolista = n1;
Nodo <int>* n4 = new Nodo<int>(0);

recorremeEsta(pseudolista);
cout << "Insertamos el nuevo nodo" <<endl;
//insertarCabezaLista(n4,pseudolista);
//insertarColaLista(n4,pseudolista);
insertarPosicion(n4,0,pseudolista);

recorremeEsta(pseudolista);

};