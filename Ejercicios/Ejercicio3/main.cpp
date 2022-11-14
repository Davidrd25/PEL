#include <iostream>
using namespace std;

template <typename T> T pila (T myNumbers[50]) {
  for (int i = 0; i < 50; i++) {
    cout << myNumbers[i] << "\n";
  }
}

int main(int, char**) {

int myNum[3] = {15, 30, 45};
int m;

m = pila <int> (myNum);

cout << "pila: " << myNum << endl;
 
 return 0;

}

