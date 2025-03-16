#include<iostream>

using namespace std;

int main() {
    // Declare arrays to hold input values and intermediate calculations
    int a[3], b[3];
    int c[3][3]; // 2D array to store the input matrix
    int i, j;

    // Read a 3x3 matrix from user input
    for(i = 0; i < 3; i++) {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }

    // Initialize the first element of array 'a' to 0
    a[0] = 0;

    // Copy the first row of the matrix 'c' into array 'b'
    for(i = 0; i < 3; i++) {
        b[i] = c[0][i];
    }

    // Calculate the remaining elements of array 'a' based on the first column of matrix 'c'
    for(i = 1; i < 3; i++) {
        a[i] = c[i][0] - b[0];
    }

    // Verify if the matrix 'c' can be represented as the sum of arrays 'a' and 'b'
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            // Check if the current element of 'c' equals the sum of corresponding elements from 'a' and 'b'
            if(c[i][j] != a[i] + b[j]) {
                cout << "No" << endl; // Output "No" if the condition fails
                return 0;   // Exit the program
            }
        }
    }

    // If all checks pass, output "Yes"
    cout << "Yes" << endl;
    return 0; // Exit the program successfully
}

