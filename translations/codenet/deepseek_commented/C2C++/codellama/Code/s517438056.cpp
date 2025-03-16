#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(void) {
    // Step 1: Reading Input
    int N, D, i, j, k = 0, n = 0;
    double l;
    int** matrix;
    cin >> N >> D;
    
    // Allocate memory for the matrix
    matrix = (int**)malloc(sizeof(int*) * N);
    for (i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * D);
    }
    
    // Step 2: Inputting Points
    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Step 3: Calculating Distances
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            int m = 0;
            for (n = 0; n < D; n++) {
                m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m;
            }
            l = sqrt(m);
            if (ceil(l) == floor(l)) k++;
        }
    }
    
    // Step 4: Outputting the Result
    cout << k << endl;
    
    // Free allocated memory
    free(matrix);
    return 0;
}

