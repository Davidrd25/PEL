#include <iostream>

using namespace std;

void imprimirMatriz( int **M, int fil, int col ){
    for( int i = 0; i < fil; i++ ){
        cout << "\n| ";
        for( int j = 0; j < col; j++ )
            cout << M[i][j] << " ";
 
        cout << " |";
    }
}

void leerMatriz (int**M, int filas, int columnas){
    cout << "\n Rellenar la matriz:\n";
    for (int i=0; i<filas; i++){
        for (int j=0; j<columnas; j++){
        cout<< "Matriz[" << i << "][" << j << "]: ";

        cin>> M[i][j];
        }
    }
}

void sumarMatrices (){

    int fil, col;

    cout << "\nLAS MATRICES HAN DE TENER LA MISMA DIMENSION\n"
         << "\nDimension de la matriz:";
    cout << "\nFilas de la matriz: "; cin >> fil;
    cout << "Columnas de la matriz: "; cin >> col;

    int **A = new int *[fil];
        for (int i=0; i<fil; i++)
        A[i] = new int [col];
    
     int **B = new int *[fil];
        for (int i=0; i<fil; i++)
        B[i] = new int [col];

    int** C = new int*[fil];
    for( int i = 0; i < fil; i++ )
        C[i] = new int[col];

    cout << "\nDatos de la matriz A: ";
    leerMatriz( A, fil, col );
 
    cout << "\nDatos de la matriz B: ";
    leerMatriz( B, fil, col );

      for( int i = 0; i < fil; i++ ){
        for( int j = 0; j < col; j++ ){
            C[i][j] = A[i][j] + B[i][j];
        }
      }
    cout << "\n\n Matriz A:\n\n";
    imprimirMatriz(A, fil, col);
    cout << "\n\n Matriz B:\n\n";
    imprimirMatriz( B, fil, col );
    cout << "\n\n Suma de las matrices C=A+B:\n\n";
    imprimirMatriz(C,fil,col);
}

void  restarMatrices(){

    int fil, col;

     cout << "\nLAS MATRICES HAN DE TENER LA MISMA DIMENSION\n"
         << "\nDimension de la matriz:";
    cout << "\nFilas de la matriz: "; cin >> fil;
    cout << "Columnas de la matriz: "; cin >> col;

    int **A = new int* [fil];
    for (int i=0; i<fil; i++){
        A [i] = new int [col];
    }

    int **B = new int* [fil];
    for (int i=0; i<fil; i++){
        B[i] = new int [col];
    }

    int **C = new int* [fil];
    for (int i=0; i<fil; i++){
        C[i] = new int [col];
    }

    cout << "\nDatos de la matriz A:\n";
    leerMatriz(A,fil,col);
    cout << "\nDatos de la matriz B\n";
    leerMatriz(B,fil,col);

    for (int i=0; i<fil; i++){
        for (int j=0; j<col;j++){
            C[i][j]= A[i][j] - B[i][j];
        }
    }

    cout << "\n\n La matriz A:\n\n";
    imprimirMatriz(A,fil,col);
    cout << "\n\n La matriz B:\n\n";
    imprimirMatriz(B,fil,col);
    cout << "\n\n La matriz C= A-B\n\n";
    imprimirMatriz(C,fil,col);
}

void multiplicarMatrices(){

    int filA, colA, filB, colB;
    
    cout << "\nLAS COLUMNAS DE A DEBEN COINCIDIR CON LAS FILAS DE B\n"
         << "\nDimension de la matriz A:\n";
    cout << "\n Filas de la matriz A:\n "; cin >> filA;
    cout << "\n Columnas de la matriz A:\n "; cin >> colA;

    int **A = new int* [filA];
    for (int i=0; i<filA; i++){
        A[i] = new int [colA];
    }

    leerMatriz(A, filA, colA);
    
    cout << "\n Dimension de la matriz B\n";
    cout << "\n Filas de la matriz B:\n "; cin >> filB;
    cout << "\n Columnas de la matriz B:\n "; cin >> colB;

    int **B = new int* [filB];
    for (int i=0; i<filA; i++){
        B[i] = new int [colB];
    }

    leerMatriz(B, filB, colB);

     int** C = new int*[filA];
    for( int i = 0; i < filA; i++ ){
        C[i] = new int[colA];
    }

    if (colA == filB){
        for (int i=0; i<filA; i++){
            for (int j=0; j<colB; j++){
                C[i][j]=0;
                for (int k=0; k<colA; k++){
                    C[i][j]= A [i][k]* B[k][j];
                 }
            }
        }
    
    cout << "\n La Matriz de A:\n\n";
    imprimirMatriz(A,filA,colA);
    cout << "\n La Matriz de B:\n\n";
    imprimirMatriz(B,filB,colB);
     cout << "\n El resultado de multiplicar las matrices: C=A*B\n\n";
    imprimirMatriz(C,filA,colB);

    }else
        cout << "\n         NO SE PUEDEN MULTIPLICAR"
                << "\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A"
                << "\nDEBE COINCIDIR CON EL DE FILAS DE LA MATRIZ B";
}

void menu (){
  cout << "\n         CALCULADORA DE MATRICES"
         << "\n============================================"
         << "\n1.- Suma de Matrices ............. (Pulsa 1)"
         << "\n2.- Resta de Matrices ............ (Pulsa 2)"
         << "\n3.- Multiplicacion de Matrices ... (Pulsa 3)"
         << "\n============================================"
         << "\nSELECCIONA UNA OPCION (1 - 3): ";  
}

int main() {
   int opcion;
 
    do{
        menu();
        cin >> opcion;
        if( cin.fail() || cin.bad() ){
            opcion = 0;
            cin.clear();
            cin.ignore( '\n', 80 );
        }
 
        switch( opcion ){
            case 1:
                sumarMatrices();
                break;
 
            case 2:
                restarMatrices();
                break;
 
            case 3:
                multiplicarMatrices();
                break;
            default:
                cout << "\n\nOPCION NO VALIDA\n\n";
                break;
        }
 
    }while( opcion != 3 );

    system("pause");
}