#include <iostream>
#include <vector>

int main() {
    int m, n; // Declare variables to store the dimensions of matrix A and vector B
    std::cin >> m >> n; // Read the dimensions of matrix A and vector B

    std::vector<std::vector<int>> A(m, std::vector<int>(n)); // Declare a 2D vector to store matrix A
    std::vector<int> B(n); // Declare a vector to store vector B
    std::vector<int> S(m, 0); // Declare a vector to store the result of matrix multiplication

    // Read the elements of matrix A row by row
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j]; // Read each element of the row
        }
    }

    // Read the elements of vector B
    for (int i = 0; i < n; i++) {
        std::cin >> B[i]; // Read each element of vector B
    }

    // Perform matrix multiplication of A and B and store the result in vector S
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            S[i] += A[i][j] * B[j]; // Accumulate the result
        }
    }

    // Print the elements of vector S
    for (int i = 0; i < m; i++) {
        std::cout << S[i] << std::endl; // Output each element of S
    }

    return 0;
}

// <END-OF-CODE>
