#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

template <typename T> class Vector{
    T * v_,         // inicio del espacio de capacidad reservada para el vector
      * space_,     // fin de la secuencia de elementos almacenados
      * last_;     // fin de la capacidad reservada para el vector

    void bounds_check(std::size_t i) const{
        if (size() < i)cout << "error throw" << endl;//throw std::out_of_range{};
    }

public:
    Vector(): v_{new T[0]}, space_{v_}, last_{v_}{}// construye un vector vacío

    Vector(Vector<T> const &v): v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()}{
        try{
            for (auto i = size_t{0}; i < v.size(); ++i)
                v_[i] = v[i];
        }
        catch (...){
            delete[] v_;
            throw;
        }
    }

    auto &operator=(Vector<T> const &rhs){
        auto tmp = Vector<T>{rhs};
        std::swap(v_, tmp.v_);
        std::swap(space_, tmp.space_);
        std::swap(last_, tmp.last_);
        return *this;
    }

    ~Vector() { delete[] v_; } // destruye el array apuntado por v_

    // funciones de capacidad_______
    auto size() const -> std::size_t { return space_ - v_; }
    auto capacity() const -> std::size_t { return last_ - v_; }
    auto empty() const -> bool { return v_ == space_; }

    // funciones de acceso______

    // sin bounds checking:
    auto operator[](std::size_t i) -> T & { return v_[i]; }
    auto operator[](std::size_t i) const -> T const & { return v_[i]; }
    // con bounds checking:
    auto at(std::size_t i) -> T &{
        bounds_check(i);
        return v_[i];
    }
    auto at(std::size_t i) const -> T const &{
        bounds_check(i);
        return v_[i];
    }

    auto begin() -> T * { return v_; }
    auto begin() const -> T const * { return v_; }
    auto end() -> T * { return space_; }
    auto end() const -> T const * { return space_; }

    // Función Push Back
    auto push_back(T const &val){
        if (space_ == last_){                    // capacidad agotada o primera vez que invocamos push_back
            std::size_t cp = capacity(),         // capacidad actual del vector
                new_cp = (cp == 0) ? 2 : 2 * cp; // nueva capacidad
            T *new_block = new T[new_cp];        // nuevo bloque de memoria
            try{
                for (auto i = std::size_t{}; i < cp; ++i)
                    new_block[i] = v_[i];
                new_block[cp] = val;
            }
            catch (...){            // de lanzarse una excepción...
                delete[] new_block; //... destruimos el nuevo array...
                throw;              // ...y relanzamos la excepción
            }
            // destruimos el array original y reasignamos los punteros:
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        else{
            *space_ = val;
            ++space_;
        }
    }
};

//Clase videoclub, donde tendremos nuestros valores de titulo, precio, tipo y si
//esta alquilado, crearemos un vector para tener los valores guardados
class Perrera{
private:
    string perro, raza;
    int edad;
    bool disponible;

public:
    Perrera() {}
    ~Perrera() {}

    string getPerro() const { return perro; }
    string getRaza() const { return raza; }
    int getEdad() const { return edad; }
    bool getDisponible() const { return disponible; }
    void setDisponible(bool dis) { disponible = dis; }

    Perrera(string p, string r, int e, bool d){
        this->perro = p;
        this->raza = r;
        this->edad = e;
        this->disponible = d;
    }
};

void buscarRaza(string raza, Vector<Perrera> vector){
    bool busquedaExitosa = false;
    for (size_t i = 0; i < vector.size(); i++){
        if (strncasecmp(raza.c_str(), vector.at(i).getRaza().c_str(), raza.size()) == 0 && vector.at(i).getDisponible() == true){
            cout << "El perro con nombre " << vector.at(i).getPerro() << ", de raza " << vector.at(i).getRaza() << ". Esta disponible" << endl;
            busquedaExitosa = true;
        }
    }
    if (!busquedaExitosa){
        cout << "No se ha encontrado ningun perro de esta raza " << endl;
    }
}
void buscarPorEdad(int edad, Vector<Perrera> vector){
    bool busquedaExitosa = false;
    for (size_t i = 0; i < vector.size(); i++){
        if (vector.at(i).getEdad() <= edad && vector.at(i).getDisponible() == true){
            cout << "El perro con nombre " << vector.at(i).getPerro() << " Esta disponible, con la edad de " << vector.at(i).getEdad() << " y raza " << vector.at(i).getRaza() << endl;
            busquedaExitosa = true;
        }
    }
    if (!busquedaExitosa){
        cout << "No se ha encontrado ningun perro de  " << edad << " anos de edad o inferior " << endl;
    }
}

Vector<Perrera> adoptarPerro(Vector<Perrera> vector){
    string perro, raza;
    cout << "Introduce el nombre del perro: ";
    cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
    char str[50000];
    cin.getline(str, 50000, '\n');
    perro = str;

    cout << "Introduce la raza del perro: ";
    char str2[50000];
    cin.getline(str2, 50000, '\n');
    raza = str2;

    bool busquedaExitosa = false;
    for (size_t i = 0; i < vector.size(); i++){
        //Comparamos si el nombre y la raza del perro coinciden a las introducidas y si el perro esta disponible
        if (strncasecmp(perro.c_str(), vector.at(i).getPerro().c_str(), perro.size()) == 0 && strncasecmp(raza.c_str(), vector.at(i).getRaza().c_str(), raza.size()) == 0 && vector.at(i).getDisponible()){
            vector.at(i).setDisponible(false);
            busquedaExitosa = true;
            cout << "Has adoptado el perro " << vector.at(i).getPerro() << ", de raza " << vector.at(i).getRaza() << endl;
        }
    }
    if (!busquedaExitosa){
        cout << "No se ha encontrado ningun perro disponible con esas caracteristicas. Por lo que no ha sido posible adoptar a " << perro << endl;
    }
    return vector;
}
Vector<Perrera> devolverPerro(Vector<Perrera> vector){
    string perro, raza;
    cout << "Introduce el nombre del perro: ";
    cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
    char str[50000];
    cin.getline(str, 50000, '\n');
    perro = str;

    cout << "Introduce la raza del perro: ";
    char str2[50000];
    cin.getline(str2, 50000, '\n');
    raza = str2;
    bool busquedaExitosa = false;
    for (size_t i = 0; i < vector.size(); i++){
        //Comparamos si el nombre y la raza del perro coinciden a las introducidas y si el perro esta disponible
        if (strncasecmp(perro.c_str(), vector.at(i).getPerro().c_str(), perro.size()) == 0 && strncasecmp(raza.c_str(), vector.at(i).getRaza().c_str(), raza.size()) == 0 && !vector.at(i).getDisponible()){
            vector.at(i).setDisponible(true);
            busquedaExitosa = true;
            cout << "Has abandonado el perro " << vector.at(i).getPerro() << ", de raza " << vector.at(i).getRaza() << ". Really George? :(" << endl;
        }
    }
    if (!busquedaExitosa){
        cout << "No se ha encontrado ningun perro disponible con esas caracteristicas. Por lo que no ha sido posible abandonar a " << perro << endl;
    }
    return vector;
}
Vector<Perrera> rescatarPerro(Vector<Perrera> vector){
    string perro, raza, auxEdad;
    int edad;
    cout << "Introduce el nombre del perro: ";
    cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
    char str[50000];
    cin.getline(str, 50000, '\n');
    perro = str;
    cout << "Introducela edad del perro: ";
    char str1[50000];
    cin.getline(str1, 50000, '\n');
    auxEdad = str1;
    edad = stoi(auxEdad);
    cout << "Introduce la raza del perro: ";
    char str2[50000];
    cin.getline(str2, 50000, '\n');
    raza = str2;

    Perrera p = {perro, raza, edad, true};
    vector.push_back(p);

    return vector;
}

Vector<Perrera> rellenarVector(Vector<Perrera> vectorPerrera){
    Perrera perro = {"ruben", "caniche", 2, true};
    vectorPerrera.push_back(perro);
    perro = {"ruben", "caniche", 2, true};
    vectorPerrera.push_back(perro);
    perro = {"jorge", "Pastor Aleman", 5, true};
    vectorPerrera.push_back(perro);
    perro = {"rober", "salchicha", 8, false};
    vectorPerrera.push_back(perro);
    perro = {"david", "bulldog", 10, true};
    vectorPerrera.push_back(perro);
    perro = {"diego", "labrador", 12, true};
    vectorPerrera.push_back(perro);
    perro = {"miguel", "caniche", 4, true};
    vectorPerrera.push_back(perro);
    return vectorPerrera;
}

int main(int, char **){
    Vector<Perrera> vector;
    vector = rellenarVector(vector);

    int opcion, edad;
    string raza, auxEdad, perro;
    do{
        cout << "1 - Buscar por Raza\n2 - Buscar por Edad\n3 - Adoptar Perro\n4 - Devolver Perro\n5 - Rescatar Perro\n0 - Salir\nIntroduce un numero: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            //Buscamos por la raza del perro
            cout << "Introduce la raza del perro:" << endl;
            cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
            char str[50000];
            //getLine solo detecta char por lo que se utiliza un char que luego lo convertimos nuevamente en string
            cin.getline(str, 50000, '\n');
            raza = str;
            buscarRaza(raza, vector);
            break;
        case 2:
            //Buscamos por la edad del perro
            cout << "Introduce la edad maxima del perro:" << endl;
            cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
            char str2[50000];
            //getLine solo detecta char por lo que se utiliza un char que luego lo convertimos nuevamente en string
            cin.getline(str2, 50000, '\n');
            auxEdad = str2;
            edad = stoi(auxEdad);
            buscarPorEdad(edad, vector);
            break;
        case 3:
            //Adoptar perro de la perrera
            vector = adoptarPerro(vector);
            break;
        case 4:
            //Devolver perro a la perrera (Abandonar)
            cout << "Perros adoptados: " << endl;
            for (auto &&i : vector){
                if (i.getDisponible() == false){
                    cout << i.getPerro() << " raza: " << i.getRaza() << endl;
                }
                
            }
            vector = devolverPerro(vector);
            break;
        case 5:
            //Agregar perro que nunca ha estado en la perrera
            vector = rescatarPerro(vector);
            break;
        case 0:
            cout << "Cerrando el programa." << endl;
            break;
        }

    } while (opcion != 0);
}