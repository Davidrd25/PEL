#include <iostream>
#include <ctime>
using namespace std; 


int numeroAleatorio()
{

    int numAleatorio;

    numAleatorio = 1+rand()%(100);

    return numAleatorio;

}

bool compararNumeros(int valorUsuario, int numAleatorio)
{
    bool acierto = false;  

    if(valorUsuario < numAleatorio)
    {
        cout << "el numero introducido es menor \n";
    }
    else if(valorUsuario > numAleatorio)
    {
        cout << "el numero introducido es mayor \n";
    }
    else
    {
        cout << "MUY BIEN!! ACERTASTEEEE!! \n";

        acierto = true;
    }

    return acierto;
}

int main(int, char**) 
{
    int contador, valorUsuario, numAleatorio = 0;
    bool acierto = false;

    numAleatorio = numeroAleatorio();

    cout << "Nuuuuumero aleatorio: "<< numAleatorio << "\n";

    cout << "INTENTA ADIVINAR EL NUMERO!!! \n";
     

     while (acierto == false)
     {
        cout << "Introduce un numero \n";
        cin >> valorUsuario;
        acierto = compararNumeros(valorUsuario, numAleatorio);
        contador = contador + 1;
     }
    
     cout << "FIN DEL JUEGO \n";
     cout << "Numero de intentos: " << contador << "\n";
     
}