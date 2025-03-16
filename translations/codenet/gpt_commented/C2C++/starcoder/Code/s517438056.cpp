#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(void) {
    // Declare variables for number of vectors (N), dimensions (D), and loop counters
    int N, D, i, j, k = 0, n = 0;
    double l; // Variable to store the distance between two vectors
    int** matrix; // Pointer to a 2D array to hold the vectors

    // Read the number of vectors (N) and their dimensions (D) from user input
    cin >> N >> D;

    // Allocate memory for a 2D array (matrix) to hold N vectors of D dimensions
    matrix = new int*[N];
    for (i = 0; i < N; i++) {
        matrix[i] = new int[D];
    }

    // Read the vectors from user input and store them in the matrix
    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate the pairwise distances between all vectors
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            int m = 0; // Variable to accumulate the squared differences
            // Calculate the squared distance between vector i and vector j
            for (n = 0; n < D; n++) {
                m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m;
            }
            // Calculate the Euclidean distance
            l = sqrt(m);
            // Check if the distance is an integer (i.e., if its ceiling equals its floor)
            if (ceil(l) == floor(l)) k++;
        }
    }

    // Output the count of pairs of vectors with integer distances
    cout << k << endl;

    // Free the allocated memory for the matrix
    for (i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
