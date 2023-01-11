//Declarar una clase punto que represente un punto dentro de un plano(coordenadas x e y), y genera una clase Nodo cuyo campo de valor sea "punto"

#include <iostream>
using namespace std;

class punto{
private:
    int x,y;
public:
punto(){}
    punto(int x, int y){
        punto::x = x;
        punto::y = y;
        }
        void imprimir() const{
            cout<< "("<< x << "," << y << ")" << endl;
        }
    ~punto(){};
};

class Nodo{
    private:
        punto dato;
        Nodo* enlace;
    public:
        Nodo (punto d){
            Nodo::dato = d;
            Nodo::enlace = 0;
        }
    public:
        Nodo (punto p, Nodo* n){
            Nodo::dato = p;
            Nodo::enlace = n;
        }
        void imprimirDato() const{
            dato.imprimir();
        }
        Nodo* devolverEnlace() const{
            return enlace;
        }

        void enlaceNodo(Nodo* sgte){
            enlace = sgte;
        }
};

void recorremeEsta(Nodo* pseudoLista){
    bool existe_enlace = true;
    while(existe_enlace == true){
        pseudoLista->imprimirDato();
        if (pseudoLista->devolverEnlace()== NULL){
            existe_enlace = false;
        }else{
            pseudoLista = pseudoLista->devolverEnlace();
        }
    }
}
int main (int, char**) {

    punto* p1 = new punto(2,2);
    punto* p2 = new punto(3,3);
    punto* p3 = new punto(4,4);


    Nodo* n1 = new Nodo(*p1);
    Nodo* n2 = new Nodo(*p2);
    Nodo* n3 = new Nodo(*p3);

    n1->enlaceNodo(n2);
    n2->enlaceNodo(n3);

    recorremeEsta(n1);
    return 0;
}