#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

int main() {
    // Declare variables for number of vectors (N), dimensions (D), and loop counters
    int N, D, i, j, k = 0, n = 0;
    double l; // Variable to store the distance between two vectors
    std::vector<std::vector<int>> matrix; // Vector of vectors to hold the vectors

    // Read the number of vectors (N) and their dimensions (D) from user input
    std::cin >> N >> D;

    // Allocate memory for a 2D vector to hold N vectors of D dimensions
    matrix.resize(N, std::vector<int>(D));

    // Read the vectors from user input and store them in the matrix
    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculate the pairwise distances between all vectors
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            int m = 0; // Variable to accumulate the squared differences
            // Calculate the squared distance between vector i and vector j
            for (n = 0; n < D; n++) {
                m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
            }
            // Calculate the Euclidean distance
            l = sqrt(m);
            // Check if the distance is an integer (i.e., if its ceiling equals its floor)
            if (std::ceil(l) == std::floor(l)) k++;
        }
    }

    // Output the count of pairs of vectors with integer distances
    std::cout << k << std::endl;

    return 0;
}
