#include <iostream>
#include <cmath>
#include <vector>

int main() {
    // Declare variables for number of vectors (N), dimensions (D), and loop counters
    int N, D, k = 0;
    double l; // Variable to store the distance between two vectors
    std::vector<std::vector<int>> matrix; // 2D vector to hold the vectors

    // Read the number of vectors (N) and their dimensions (D) from user input
    std::cin >> N >> D;

    // Resize the 2D vector to hold N vectors of D dimensions
    matrix.resize(N, std::vector<int>(D));

    // Read the vectors from user input and store them in the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculate the pairwise distances between all vectors
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int m = 0; // Variable to accumulate the squared differences
            // Calculate the squared distance between vector i and vector j
            for (int n = 0; n < D; n++) {
                m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
            }
            // Calculate the Euclidean distance
            l = sqrt(m);
            // Check if the distance is an integer (i.e., if its ceiling equals its floor)
            if (ceil(l) == floor(l)) k++;
        }
    }

    // Output the count of pairs of vectors with integer distances
    std::cout << k << std::endl;

    return 0;
}

// <END-OF-CODE>
