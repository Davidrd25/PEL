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
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(){

    list <int> num = {1,2,3,4,5,6,7,8,10,12};
    
    //Creo la lista numeros
    list<int> numeros;
    int numero;

    //Pido los números al usuario
    cout<<"Introduce una serie de numeros aleatorios. Para terminar la serie introduce (-1): "<<endl;
    cin>>numero;

    //Mientras el usuario no introduzca -1, se seguirá pidiendo números
    while(numero != -1){
        //Inserto el número en la lista
        int mitad = num.size()/2;
        //Creo un iterador para recorrer la lista
        list<int>::iterator it = num.begin();
        advance(it,mitad);
        num.insert(it,numero);
        
        cin>>numero;
    }

    //Creo un iterador para recorrer la lista
    list<int>::iterator it;

    //Recorro la lista y muestro los números impares
    for(int i=0; i<num.size();i++){
        it =num.begin();
        advance(it,i);
        if(*it % 2 != 0){
            cout<<*it<<endl;
        }

    }

    return 0;


}