#include <iostream>
using namespace std;

class Discografica{
private:
    string grupo, titulo, genero;
public:
    Discografica(){}
    Discografica(string grup, string title, string gen){
        Discografica::grupo = grup;
        Discografica::titulo = title;
        Discografica::genero = gen;        
    }
    string getGrupo(){
        return Discografica::grupo;
    }
    string getTitulo(){
        return Discografica::titulo;
    }
    string getGenero(){
        return Discografica::genero;
    }
};

template<typename T> class Vector{
    private:
        T * v_, // puntero que apunta al principio
          * space_, // puntero que apunta al ultimo elmento lleno mas uno
          * last_; // puntero que apunta al siguiente bloque del ultimo espacio del vector
        
    public:
        Vector(): v_{new T[0]}, space_{v_}, last_{v_} {} // constructor inicializado a 0
        Vector(Vector<T> const& v): v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()} {
            try{
                for (auto i = size_t{0}; i < v.size(); i++){
                v_[i] = v[i];
            }
            }
            catch(...){
                delete[] v_;
                throw;
            }    
        }//contructor copia

        ~Vector(){delete[] v_;}

        //METODOS: Size(); Capacity(); Begin(); End();
        //Metodos de capacidad
        //size_t size() {return space_ - v_;} --> esto es igual que la de abajo pero la de abajo es mejor :)
        auto size() const -> size_t {return space_ - v_;} // Se hace constante del sistema. La flecha le declara el tipo porque es un "metodo puntero"
        auto capacity() const -> size_t {return last_ - v_;};
        auto empty() const -> bool {return v_ == space_;}

        //Metodos de acceso
        auto begin() const -> T const* {return v_;}
        auto end() const -> T const* {return space_;}

        //Metodo Push_back
        void push_back(T const& valor){
            if (space_ == last_){
                size_t cap = capacity(), new_cap = (cap == 0)? 2 : 2*cap;
                T* new_block = new T[new_cap];
                try{
                    for (auto i = size_t{0}; i < cap; i++){
                    new_block[i] = v_[i];
                    }
                    new_block[cap] = valor;
                }
                catch(...){
                    delete[] new_block;
                    throw;
                }
                delete[] v_;
                v_ = new_block;
                space_ = new_block + cap + 1;
                last_ = new_block + new_cap;           
            }else{
                *space_ = valor;
                ++space_;
            }
        }
};

int main(int, char**) {
    Vector<Discografica> discos;
    Discografica* d0 = new Discografica("Queen","Greatest Hits","pop");
    discos.push_back(*d0);
    Discografica* d1 = new Discografica("The Beatles","The Beatles","pop");
    discos.push_back(*d1);
    Discografica* d2 = new Discografica("Bad Bunny","yhlqmdlg","reggaeton");
    discos.push_back(*d2);
    Discografica* d3 = new Discografica("ACDC","The Razors Edge","rock");
    discos.push_back(*d3);
    Discografica* d4 = new Discografica("Queen","Bohemian Rhapsody","pop");
    discos.push_back(*d4);
    Discografica* d5 = new Discografica("La Rosalia","Motomami","reggaeton");
    discos.push_back(*d5);
    Discografica* d6 = new Discografica("Natos y Waor","Cicatrices","rap");
    discos.push_back(*d6);
    Discografica* d7 = new Discografica("Bad Bunny","Un Verano sin ti","reggaeton");
    discos.push_back(*d7);
    Discografica* d8 = new Discografica("Don Omar","iDon","reggaeton");    
    discos.push_back(*d8);
    
    int i = 1, num;
    bool salir = false;
    while (!salir){
        bool encontrado = false;    
        cout << "1-Aniadir album \n2-Buscar \n3-Salir \nIntroducaca Numero: ";
        cin >> num;
        if (num == 1){
            string g,t,ge;
            cout << "Grupo/Cantatnte: ";
            cin.ignore();
            getline(cin, g);
            cout << "Titulo: ";
            getline(cin, t);
            cout << "Genero: ";
            getline(cin, ge);
            cout << endl;
            Discografica* d = new Discografica(g,t,ge);
            discos.push_back(*d);
        }else if (num == 2){
            string buscar;
            cout << "Buscar: ";
            cin.ignore();
            getline(cin, buscar);
            cout << endl;
            for(Discografica p : discos){
                if(buscar == p.getGenero() || buscar == p.getTitulo() || buscar == p.getGrupo()){
                    cout << i << "-Disco " << p.getTitulo() << " de " << p.getGrupo() << " - " << p.getGenero() << endl;
                    i++;
                    encontrado = true;
                }
            }
            if (encontrado == false){
                cout << "No se ha podido encontrar el album" << endl;
            }
            cout << endl;
        }else if (num == 3){
            salir = true;
            cout << "Saliste!!";
        }
    } 
    discos.~Vector();    
}