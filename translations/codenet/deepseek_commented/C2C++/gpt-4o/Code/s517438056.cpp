#include <iostream>
#include <cmath>
#include <vector>

int main() {
    // Step 1: Reading Input
    int N, D, k = 0;
    std::cin >> N >> D;

    // Allocate memory for the matrix using a vector
    std::vector<std::vector<int>> matrix(N, std::vector<int>(D));

    // Step 2: Inputting Points
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Step 3: Calculating Distances
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int m = 0;
            for (int n = 0; n < D; n++) {
                m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
            }
            double l = std::sqrt(m);
            if (std::ceil(l) == std::floor(l)) k++;
        }
    }

    // Step 4: Outputting the Result
    std::cout << k << std::endl;

    return 0;
}

// <END-OF-CODE>
