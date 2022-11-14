#include <iostream>
using namespace std;



template <typename T> T intercambio (T a, T b, T c){
    c=a;
    a=b;
    b=c;
  return (a && b);
}



int main(int, char**) {
        
    int a = 4, b=6, g, n;
    double c = 6.5, d = 1.3, e, m;

    n = intercambio <int> (a,b,g);
    m = intercambio <double> (c,d,e);

    cout << "cambio de reales" << m << endl;
    cout << "cambio de enteros" << n << endl;
    
    return 0; 
}
