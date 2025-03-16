#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

int main() {
    // Step 1: Reading Input
    int N, D, i, j, k = 0, n = 0;
    double l;
    std::vector<std::vector<int>> matrix;
    std::cin >> N >> D;
    
    // Allocate memory for the matrix
    matrix.resize(N, std::vector<int>(D));
    
    // Step 2: Inputting Points
    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    // Step 3: Calculating Distances
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            int m = 0;
            for (n = 0; n < D; n++) {
                m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
            }
            l = std::sqrt(m);
            if (std::ceil(l) == std::floor(l)) k++;
        }
    }
    
    // Step 4: Outputting the Result
    std::cout << k << std::endl;
    
    return 0;
}
