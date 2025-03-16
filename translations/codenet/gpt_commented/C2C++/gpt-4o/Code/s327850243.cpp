#include <iostream>
using namespace std;

int main() {
    // Declare variables for the number of rows (m) and columns (n)
    int m, n;
    // Loop counters
    int i, j;
    // Declare a 2D array A for storing the matrix and a 1D array B for the vector
    int A[100][100];
    int B[100];
    // Declare an array S to store the results of the matrix-vector multiplication, initialized to 0
    int S[100] = {0};

    // Read the dimensions of the matrix (m rows and n columns)
    cin >> m >> n;

    // Input the matrix A
    for(i = 0; i < m; i++) {
        // Read each row of the matrix
        for(j = 0; j < n; j++) {
            cin >> A[i][j]; // Read elements of the row
        }
    }

    // Input the vector B
    for(i = 0; i < n; i++) {
        cin >> B[i]; // Read each element of the vector
    }

    // Perform matrix-vector multiplication
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            S[i] += A[i][j] * B[j]; // Calculate the dot product for each row
        }
    }

    // Output the result of the multiplication
    for(i = 0; i < m; i++) {
        cout << S[i] << endl; // Print each element of the result array S
    }

    return 0; // Indicate successful completion of the program
}

// <END-OF-CODE>
