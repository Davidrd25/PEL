#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

template <typename T> // T debe ser un tipo default_initializable
class VectorPEL
{
    T *v_,       // inicio del espacio de capacidad reservada para el vector
        *space_, // fin de la secuencia de elementos almacenados
        *last_;  // fin de la capacidad reservada para el vector

    void bounds_check(std::size_t i) const
    {
        if (size() < i)
            //throw std::out_of_range{};
            cout << "error throw" << endl;
    }

public:
    VectorPEL() // construye un vector vacío
        : v_{new T[0]}, space_{v_}, last_{v_}
    {
    }

    VectorPEL(VectorPEL<T> const &v)
        : v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()}
    {
        try
        {
            for (auto i = size_t{0}; i < v.size(); ++i)
                v_[i] = v[i];
        }
        catch (...)
        {
            delete[] v_;
            throw;
        }
    }

    auto &operator=(VectorPEL<T> const &rhs)
    {
        auto tmp = VectorPEL<T>{rhs};
        std::swap(v_, tmp.v_);
        std::swap(space_, tmp.space_);
        std::swap(last_, tmp.last_);
        return *this;
    }

    ~VectorPEL() { delete[] v_; } // destruye el array apuntado por v_

    // funciones de capacidad_______________
    auto size() const -> std::size_t { return space_ - v_; }
    auto capacity() const -> std::size_t { return last_ - v_; }
    auto empty() const -> bool { return v_ == space_; }

    // funciones de acceso________________

    // sin bounds checking:
    auto operator[](std::size_t i) -> T & { return v_[i]; }
    auto operator[](std::size_t i) const -> T const & { return v_[i]; }
    // con bounds checking:
    auto at(std::size_t i) -> T &
    {
        bounds_check(i);
        return v_[i];
    }
    auto at(std::size_t i) const -> T const &
    {
        bounds_check(i);
        return v_[i];
    }

    auto begin() -> T * { return v_; }
    auto begin() const -> T const * { return v_; }
    auto end() -> T * { return space_; }
    auto end() const -> T const * { return space_; }

    // Función Push Back
    auto push_back(T const &val)
    {
        if (space_ == last_)
        {                                        // capacidad agotada o primera vez que invocamos push_back
            std::size_t cp = capacity(),         // capacidad actual del vector
                new_cp = (cp == 0) ? 2 : 2 * cp; // nueva capacidad
            T *new_block = new T[new_cp];        // nuevo bloque de memoria
            try
            {
                for (auto i = std::size_t{}; i < cp; ++i)
                    new_block[i] = v_[i];
                new_block[cp] = val;
            }
            catch (...)
            {                       // de lanzarse una excepción...
                delete[] new_block; //... destruimos el nuevo array...
                throw;              // ...y relanzamos la excepción
            }
            // destruimos el array original y reasignamos los punteros:
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        else
        {
            *space_ = val;
            ++space_;
        }
    }
};

//Clase videoclub, donde tendremos nuestros valores de titulo, precio, tipo y si
//esta alquilado, crearemos un vector para tener los valores guardados
class Videoclub
{
private:
    string titulo, dvdBlueray;
    int price;
    bool disponible;

public:
    Videoclub() {}
    ~Videoclub() {}

    string getTitulo() const { return titulo; }
    int getPrice() const { return price; }
    string getDvdBlueray() const { return dvdBlueray; }
    bool getDisponible() const { return disponible; }
    void setDisponible(bool dis) { disponible = dis; }

    Videoclub(string t, int p, string tipo, bool a)
    {
        this->titulo = t;
        this->price = p;
        this->dvdBlueray = tipo;
        this->disponible = a;
    }
};

void buscadorTitulo(string titulo, VectorPEL<Videoclub> vector)
{
    bool busquedaExitosa = false;
    for (size_t i = 0; i < vector.size(); i++)
    {
        if (strncasecmp(titulo.c_str(), vector.at(i).getTitulo().c_str(), titulo.size()) == 0 && vector.at(i).getDisponible() == true)
        {

            cout << "Titulo: " << vector.at(i).getTitulo() << ", precio: " << vector.at(i).getPrice() << ", tipo: " << vector.at(i).getDvdBlueray() << " y Esta disponible para alquilar " << endl;
            busquedaExitosa = true;
        }
    }
    if (!busquedaExitosa)
    {
        cout << "No se ha encontrado ningún titulo disponible con ese nombre: " << titulo << endl;
    }
}

VectorPEL<Videoclub> alquilarTitulo(string titulo, VectorPEL<Videoclub> vector)
{
    bool busquedaExitosa = false;
    for (size_t i = 0; i < vector.size(); i++)
    {
        if (strncasecmp(titulo.c_str(), vector.at(i).getTitulo().c_str(), titulo.size()) == 0 && vector.at(i).getDisponible())
        {
            vector.at(i).setDisponible(false);
            busquedaExitosa = true;
            cout << "Has alquilado la pelicula con exito: " << vector.at(i).getTitulo() << endl;
        }
    }
    if (!busquedaExitosa)
    {
        cout << "No se ha encontrado ningun titulo disponible con ese nombre. Por lo que no ha sido posible alquilarlo " << titulo << endl;
    }
    return vector;
}
VectorPEL<Videoclub> devolverTitulo(string titulo, VectorPEL<Videoclub> vector)
{
    bool busquedaExitosa = false;
    for (size_t i = 0; i < vector.size(); i++)
    {
        if (strncasecmp(titulo.c_str(), vector.at(i).getTitulo().c_str(), titulo.size()) == 0 && !vector.at(i).getDisponible())
        {
            vector.at(i).setDisponible(true);
            busquedaExitosa = true;
            cout << "Has devuelto la pelicula al videoclub con exito: " << vector.at(i).getTitulo() << endl;
        }
    }
    if (!busquedaExitosa)
    {
        cout << "No se ha podido delvolver la pelicula, porque nunca a formado parte de este videoclub, no existe la pelicula o ya la tenemos en stock. " << titulo << endl;
    }
    return vector;
}

VectorPEL<Videoclub> agregarPelicula(VectorPEL<Videoclub> vector)
{
    string titulo, dvdBlueray, auxPrice;
    int price;
    cout << "Introduce el titulo de la pelicula:" << endl;
    cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
    char str[50000];
    cin.getline(str, 50000, '\n');
    titulo = str;
    cout << "Introduce el precio de la pelicula:" << endl;
    char str1[50000];
    cin.getline(str1, 50000, '\n');
    auxPrice = str1;
    price = stoi(auxPrice);
    cout << "Introduce si es dvd o blueray:" << endl;
    char str2[50000];
    cin.getline(str2, 50000, '\n');
    dvdBlueray = str2;

    Videoclub vc = {titulo, price, dvdBlueray, true};
    vector.push_back(vc);

    return vector;
}

//Introducimos la informacion en un vector y o cargamos en el programa
VectorPEL<Videoclub> rellenarVector(VectorPEL<Videoclub> vectorVideoclub)
{
    Videoclub vc = {"El padrino", 5, "DVD", true};
    vectorVideoclub.push_back(vc);
    vc = {"El mago de Oz", 8, "DVD", true};
    vectorVideoclub.push_back(vc);
    vc = {"Ciudadano Kane", 7, "DVD", true};
    vectorVideoclub.push_back(vc);
    vc = {"Cadena perpetua", 5, "Blu-ray", true};
    vectorVideoclub.push_back(vc);
    vc = {"Pulp Fiction", 7, "DVD", true};
    vectorVideoclub.push_back(vc);
    vc = {"Casablanca", 10, "Blu-ray", true};
    vectorVideoclub.push_back(vc);
    vc = {"El padrino II", 9, "DVD", true};
    vectorVideoclub.push_back(vc);
    vc = {"E.T., el extraterrestre", 4, "Blu-ray", true};
    vectorVideoclub.push_back(vc);
    vc = {"Una odisea del espacio", 6, "DVD", true};
    vectorVideoclub.push_back(vc);
    vc = {"La lista de Schindler", 7, "Blu-ray", false};
    vectorVideoclub.push_back(vc);

    return vectorVideoclub;
}

int main(int, char **)
{

    VectorPEL<Videoclub> vector;
    vector = rellenarVector(vector);

    int opcion;
    string titulo, tipo;
    string precio;

    do
    {
        cout << "1 - Buscar Por Titulo\n2 - Alquilar Pelicula\n3 - Devolver Pelicula\n4 - Agregar nueva pelicula\n0 - Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            //Buscar por titulo
            cout << "Introduce el titulo para buscar informacion:" << endl;
            cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
            char str[50000];
            //getLine solo detecta char por lo que se utiliza un char que luego lo convertimos nuevamente en string
            cin.getline(str, 50000, '\n');
            titulo = str;
            buscadorTitulo(titulo, vector);
            break;
        case 2:
            //Alquilar
            cout << "Introduce el titulo de la pelicula que quieres alquilar:" << endl;
            cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
            char str2[50000];
            //getLine solo detecta char por lo que se utiliza un char que luego lo convertimos nuevamente en string
            cin.getline(str2, 50000, '\n');
            titulo = str2;
            vector = alquilarTitulo(titulo, vector);
            break;
        case 3:
            //Devolver
            cout << "Introduce el titulo de la pelicula para devolver:" << endl;
            cin.ignore(); //Con esto se detiene la ejecucion para poder ingresar por pantalla datos
            char str3[50000];
            //getLine solo detecta char por lo que se utiliza un char que luego lo convertimos nuevamente en string
            cin.getline(str3, 50000, '\n');
            titulo = str3;
            vector = devolverTitulo(titulo, vector);
            break;
        case 4:
            //Agregar pelicula
            vector = agregarPelicula(vector);
            break;
        case 0:
            cout << "Cerrando el programa." << endl;
            break;
        }

    } while (opcion != 0);
}