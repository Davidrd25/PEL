/*
ENUNCIADO:
La empresa HP tiene un problema con sus servidores todas sus bases de datos son SQL y quieren cambiarlas a bases no SQl.
Para realizar la migracion de los datos se ha decidido trasladar la informacion con un contenedor y los datos se agregaran
al contenedor mediante funciones push_back. 
Posteriromente los datos del contendor de transmision se agregaran a una base de datos no relacional de estructura enlazada 
funcionando como un first-in first-out. 
Una vez terminada la migración de datos se mostrará toda la info de la nueva base de datos por consola. 
La estructura de tipo FIFO solo tiene los métodos de acceso por la parte superior
*/

#include <iostream>
using namespace std;


class Data{
public:
    int id;
    string nombre;

public:
  
    Data(int id,string nombre){
        this->id = id;
        this->nombre = nombre;
       
    }
    Data(int i,string nom){
        this->id = i;
        this->nombre = nom;
       
    }

};

template <class T> class Nodo{ 
public:
    T dato;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;
public:

    Nodo(T dato){
        this->dato = dato;
        this->siguiente = NULL;
        this->anterior = NULL;
    }
};


int main() {

    Data *d1 = new Data(1,"Juan");
    Data *d2 = new Data(2,"Pedro");
    Data *d3 = new Data(3,"Maria");
    Data *d4 = new Data(4,"Jose");
    Data *d5 = new Data(5,"Luis");

    return 0;

};


