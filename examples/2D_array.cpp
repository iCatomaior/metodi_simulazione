#include <iostream>

using namespace std;

int **GetArray(int **matrix, int L){
    int **array = matrix;

    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            array[i][j] = 5;
        }
    }

    return array;
}

int main (){

    const int L = 2;

    int **matrix = new int*[L];

    for (int i=0; i<L; i++){
        matrix[i] = new int[L];
    }

    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            matrix[i][j] = i+j;
        }
    }

    int **b = GetArray(matrix,L);

    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            cout << matrix[i][j] << endl;
        }
    }

    return 0;
}