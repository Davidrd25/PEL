#include <iostream>
using namespace std;

class Libro{
    private:
        int id;
        string nombre_libro;
        string categoria;
        string fecha_entrada;
        string fecha_salida;
        bool disponible;
        
public:
   Libro(){
        id;
        nombre_libro;
        categoria;
        fecha_entrada;
        fecha_salida; 
        disponible;
    } 

    Libro(int id, string nombre_libro,  string categoria, string fecha_entrada, string fecha_salida, bool disponible ){
        Libro::id = id;
        Libro::nombre_libro = nombre_libro;
        Libro::categoria = categoria;
        Libro::fecha_entrada = fecha_entrada;
        Libro::fecha_salida = fecha_salida; 
        Libro::disponible = disponible;
    } 

    Libro(int id, string nombre_libro,  string categoria, bool disponible){
        Libro::id = id;
        Libro::nombre_libro = nombre_libro;
        Libro::categoria = categoria;
        Libro::disponible = disponible;
    } 
    int get_id(){
        return Libro::id;
    }
    bool get_disponible(){
        return Libro::disponible;
    }
    void set_disponible(bool disponible){
        Libro::disponible = disponible;
    }
    string get_name(){
        return Libro::nombre_libro;
    }

    string to_string(){
        return "(" + std::to_string(Libro::id) + ") " + Libro::nombre_libro  + ", " + Libro::categoria + "\n";
    }
};

class Usuario{
    private:
        string DNI;
        string nombre_user;
        string apellidos_user;
        Libro libro_presente;

    public:
        Usuario(){
             DNI;
            nombre_user;
            apellidos_user;
            libro_presente;
        }

        Usuario(string DNI, string nombre_user, string apellidos_user,Libro libro_presente){
           Usuario::DNI = DNI;
           Usuario::nombre_user = nombre_user;
           Usuario::apellidos_user = apellidos_user;
            Usuario::libro_presente = libro_presente;     
        }

        Usuario(string DNI, string nombre_user, string apellidos_user){
           Usuario::DNI = DNI;
           Usuario::nombre_user = nombre_user;
           Usuario::apellidos_user = apellidos_user;
        }

        string get_dni(){
            return Usuario::DNI;
        }

        Libro get_libro_presente(){
            return Usuario::libro_presente;
        }

        void set_libro_presente( Libro libro){
             Usuario::libro_presente = libro;
        }

        string to_string(){
            return "(" + Usuario::DNI + ") " + Usuario::nombre_user  +  " " + Usuario::apellidos_user + "\n";
        }
};

template <typename T> class Historial{
    private:
            Libro datos[50];
            int num_elementos;
            T usuario;
    public:
        // constructor de una pila vacía:
        Historial(): num_elementos(0) {}
        Historial(T usuario){
            Historial::usuario = usuario;
        }
        // Función de inserción de elementos dentro de una pila;
        void insert(Libro elem){
            if (num_elementos < 50){
                datos[num_elementos] = elem;
                num_elementos ++;
            }
            else{
                cout << "Historial lleno";
            }
        }
        // Función de extracción de elemento de una pila;
        void extract(){   
            if (num_elementos > 0){
                for (int i = 0; i < num_elementos; i++){
                    cout << datos[i].to_string();
                }
            }
            else{
                cout << "No hay historial disponible" << endl;
            }
        }

        int tamanio_pila(){
            return num_elementos;
        }
        bool es_vacia(){
            return num_elementos == 0;
        }
};

void ver_libros_disponibles(Libro libros_array[]){
    cout << "**LIBROS DISPONIBLES**\n";
    for (int i = 0; i < 20; i++){
        if(libros_array[i].get_disponible() == true){
            cout << libros_array[i].to_string();
        }
    }
};

void ver_libros_no_disponibles(Libro libros_array[]){
    for (int i = 0; i < 20; i++){
        if(libros_array[i].get_disponible() == false){
            cout << libros_array[i].to_string();
        }
    }
};

void sacar_libro(Libro libros_array[], Libro libro){
    for (int i = 0; i < 20; i++){
        if(libros_array[i].get_id() == libro.get_id()){
            libros_array[i].set_disponible(false);
        }
    }
};

void guardar_libro(Libro libros_array[], Libro libro){
    for (int i = 0; i < 20; i++){
        if(libros_array[i].get_id() == libro.get_id()){
            libros_array[i].set_disponible(true);
        }
    }
};

void ver_usuarios(Usuario usuarios_array[]){
    cout << "USUARIOS REGISTRADOS\n";
    for (int i = 0; i < 3; i++){
        cout << std::to_string(i + 1)  + "-" + usuarios_array[i].to_string();
    }
}

Usuario switch_elegir_usuario(Usuario usuarios_array[]){
    int opcion = 0;
    cout << "Introduce el nunero del usuario: ";
    cin >> opcion;

    switch (opcion){
        case 1:
            return usuarios_array[0];
            break;
        case 2:
            return usuarios_array[1];
            break;
        case 3:
            return usuarios_array[2];
            break;
    };
}

void ver_libro_actual(Usuario usuario){
    if (usuario.get_libro_presente().get_name() == ""){
        cout << "No hay libro actual" << endl;
    } 
    else{
        cout << usuario.get_libro_presente().to_string();
    }
}

Libro escoger_libro(Libro libros_array[]){
    int num = 0;
    cout << "Escoja el id del Libro: ";
    cin >> num;
    for (int i = 0; i < 20; i++){
        if(libros_array[i].get_id() == num){
            return libros_array[i];
        }
    }
}

Usuario quitar_libro(Usuario usuarios_array[],Libro libro){
    for (int i = 0; i < 3; i++){
        if (usuarios_array[i].get_libro_presente().get_id() == libro.get_id()){
            return usuarios_array[i];
        }
    }
}

void menu(){
    cout << "\tMENU" << endl;
    cout << "1-Comprobar libros disponibles" << endl;
    cout << "2-Ver el historial de libros de una persona" << endl;
    cout << "3-Ver si una persona tiene un libro" << endl;
    cout << "4-Asignar un libro a una persona" << endl;
    cout << "5-Devolver un libro" << endl;
    cout << "6-Salir" << endl;
    cout << " Escoja una opcion: ";
}

int main(int, char**) {
//LIBROS
    Libro l1(1,"Platero y yo", "Infantil",false);
    Libro l2(2,"Don Quijote2", "Aventura",true);
    Libro l3(3,"Don Quijote3", "Aventura",true);
    Libro l4(4,"Don Quijote4", "Aventura",true);
    Libro l5(5,"Don Quijote5", "Aventura",true);
    Libro l6(6,"Don Quijote6", "Aventura",true);
    Libro l7(7,"Don Quijote7", "Aventura",true);
    Libro l8(8,"Don Quijote8", "Aventura",true);
    Libro l9(9,"Don Quijote9", "Aventura",true);
    Libro l10(10,"Don Quijote10", "Aventura",true);
    Libro l11(11,"Don Quijote11", "Aventura",true);
    Libro l12(12,"Don Quijote12", "Aventura",true);
    Libro l13(13,"Don Quijote13", "Aventura",true);
    Libro l14(14,"Don Quijote14", "Aventura",true);
    Libro l15(15,"Don Quijote15", "Aventura",true);
    Libro l16(16,"Don Quijote16", "Aventura",true);
    Libro l17(17,"Don Quijote17", "Aventura",true);
    Libro l18(18,"Don Quijote18", "Aventura",true);
    Libro l19(19,"Don Quijote19", "Aventura",true);
    Libro l20(20,"Don Quijote20", "Aventura",true);

    Libro libros_array[20] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l18,l19,l20};
    
//USUARIOS
    Usuario user1("123456A", "David", "Rodriguez",l1);
    Usuario user2("3456789B","Alvaro","Tunion");
    Usuario user3("23454678C", "Andres", "Perez");

    Usuario usuarios_array[3] = {user1,user2,user3};
    
    Historial <Usuario> historialDavid(user1);
    Historial <Usuario> historialAlvaro(user2);
    Historial <Usuario> historialAndres(user3);

    historialDavid.insert(l1);
    historialDavid.insert(l5);
    historialDavid.insert(l6);
    historialAndres.insert(l4);
    historialAndres.insert(l11);
    historialAndres.insert(l16);

    int opcion;
    bool salir = false;  
    Usuario usu;
    Libro lib,libro_vacio;
    do{
        Usuario usuarios_array[3] = {user1,user2,user3};
        menu();
        cin >> opcion;
        switch (opcion){
        case 1:
            ver_libros_disponibles(libros_array);
            cout << "**LIBROS NO DISPONIBLES**\n";
            ver_libros_no_disponibles(libros_array);
            break;
        case 2:
            ver_usuarios(usuarios_array);
            usu = switch_elegir_usuario(usuarios_array);
            if (usu.get_dni() == user1.get_dni()){
                historialDavid.extract();
            }else if (usu.get_dni() == user2.get_dni()){
                historialAlvaro.extract();
            }else if (usu.get_dni() == user3.get_dni()){
                historialAndres.extract();
            }
            break;
        case 3:
            ver_usuarios(usuarios_array);
            usu = switch_elegir_usuario(usuarios_array);
            ver_libro_actual(usu);
            break;
        case 4:
            ver_libros_disponibles(libros_array);
            lib = escoger_libro(libros_array);
            ver_usuarios(usuarios_array);
            usu = switch_elegir_usuario(usuarios_array);
            if (usu.get_dni() == user1.get_dni() && user1.get_libro_presente().get_name() == ""){
                historialDavid.insert(lib);
                user1.set_libro_presente(lib);
            }else if (usu.get_dni() == user2.get_dni() && user2.get_libro_presente().get_name() == ""){
                historialAlvaro.insert(lib);
                user2.set_libro_presente(lib);
            }else if (usu.get_dni() == user3.get_dni() && user3.get_libro_presente().get_name() == ""){
                historialAndres.insert(lib);
                user3.set_libro_presente(lib);
            }else{
                cout << "Ya tiene un libro asignado!!!" << endl;
                break;
            }
            sacar_libro(libros_array,lib);
            break;
        case 5:
            cout << "**LIBROS A DEVOLVER**\n";
            ver_libros_no_disponibles(libros_array);
            lib = escoger_libro(libros_array);
            guardar_libro(libros_array,lib);
            usu = quitar_libro(usuarios_array,lib);
            if (usu.get_dni() == user1.get_dni()){
                user1.set_libro_presente(libro_vacio);
            }else if (usu.get_dni() == user2.get_dni()){
                user2.set_libro_presente(libro_vacio);
            }else if (usu.get_dni() == user3.get_dni()){
                user3.set_libro_presente(libro_vacio);
            }
            break;
        case 6:
            salir = true;
            break;
        }
    }while(!salir);
    
};