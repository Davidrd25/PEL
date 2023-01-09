#include <iostream>
using namespace std;

int main(){

	int matriz [3][3];
    int n=3;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"Que numero desea en la posicion "<<i<<","<<j<<": ";
			cin>>matriz[i][j];
		}
	}

    cout<<"Matriz original: "<<endl;
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<matriz[i][j];
		}
        cout<<endl;
	}

    cout<<"Matriz transpuesta: "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<matriz[j][i];
		}
	cout<<endl;
	}

	return 0;
}