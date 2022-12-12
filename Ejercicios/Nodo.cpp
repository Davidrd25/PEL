#include <iostream>
using namespace std;

template <typename T> class Nodo{
    private:
        T dato;
        Nodo<T>* enlace;
    public:
        Nodo (T d){
            Nodo::dato = d;
            Nodo::enlace = 0;
        }
    public:
        Nodo (T p, Nodo<T>* n){
            Nodo::dato = p;
            Nodo::enlace = n;
        }
        T datoNodo() const{
            return dato;
        }
        Nodo* devolverEnlace() const{
            return enlace;
        }

        void enlaceNodo(Nodo<T>* sgte){
            enlace = sgte;
        }
};

template <typename T> void recorremeEsta(Nodo<T>* pseudoLista){
    bool existe_enlace = true;
    while(existe_enlace == true){
        cout<< pseudoLista->datoNodo() << endl;
        if (pseudoLista->devolverEnlace()== NULL){
            existe_enlace = false;
        }else{
            pseudoLista = pseudoLista->devolverEnlace();
        }
    }
}

int main (int, char**) {

    Nodo<int>* n1 = new Nodo(2);
    Nodo<int>* n2 = new Nodo(4);
    Nodo<int>* n3 = new Nodo(6);

    n1->enlaceNodo(n2);
    n2->enlaceNodo(n3);

    recorremeEsta<int>(n1);

};
