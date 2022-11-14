#include <iostream>
using namespace std;

class Hora{
    public:
    int hora,min,seg;
    Hora();
    Hora(int h, int m, int s);
    void mostrar_hora();
    void suma_horas( Hora h1, Hora h2);
};

Hora::Hora(){
    Hora::hora = 0;
    Hora::min = 0;
    Hora::seg = 0;
}

Hora::Hora(int h, int m, int s){
    Hora::hora = h;
    Hora::min = m;
    Hora::seg = s;
}

void Hora:: mostrar_hora(){
    cout<<Hora::hora << ":"<<Hora::min << ":" << Hora::seg <<endl;
}


void Hora::suma_horas( Hora h1, Hora h2){
    Hora::hora=h1.hora +h2.hora;
    Hora::min=h1.min +h2.min;
    Hora::seg=h1.seg +h2.seg;

    if (Hora::seg>59){
        Hora::seg = Hora:: seg -60;
        Hora::min = Hora:: min + 1;
    }

    if (Hora::min>59){
        Hora::min = Hora:: min -60;
        Hora::hora = Hora:: hora + 1;
    }

    if (Hora::hora>23){
        Hora::hora = Hora::hora -24;
    }

}

    

int main (int,char**){
    Hora reloj1 (20,27,30);
    Hora reloj2 (16,44,06);
    Hora reloj3;
    reloj3.suma_horas(reloj1,reloj2);
    reloj1.mostrar_hora();
    reloj2.mostrar_hora();
    reloj3.mostrar_hora();
    return 0;

}
