#include <iostream>
using namespace std;

template <typename T> T menor(T a, T b){
  return (a < b ? a : b);
}
template <typename T> T mayor(T a, T b){
    return (a > b ? a : b);
}


int main(int, char**) {
    
    
    int a =4, b = 6, n, p; 
    double c = 8.3, d = 9.4, m, l;

    
    n = menor <int> (a,b); 
    p = mayor <int> (a,b);

    m = menor <double> (c,d); 
    l = mayor <double> (c,d);

    
    cout << "Entero menor: " << n << endl;
    cout << "Entero mayor: " << p << endl;
        
    cout << "Real menor: " << m << endl;
    cout << "Real mayor: " << l << endl;

    
    return 0; 
}