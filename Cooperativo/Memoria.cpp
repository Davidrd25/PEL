#include <iostream>
using namespace std;
class X {
    private:
        int id;
    public:
        X(){
            X:: id = 0;
        }

        X(int ident){
            X::id = ident;
        }

        void print(){
            cout << to_string(X::id) << endl;
        }

        ~X(){
            cout << "El elemento ha sido eliminado";
        };

        X eliminar(){
            X:: ~X();
            cout << "El elemento ha sido eliminado";
        };
};

int main(int, char**) {
    X* p_array = new X[3] {X( 2), X(3), X(4)};

    for (int i = 0; i<3; i++){
        p_array ->print();
        //p_array[i].imprimir();
        p_array ++;
    }

        for (int i = 0; i<3; i++){
        p_array ->print();
        //p_array[i].eliminar();
        p_array ++;
    }


};