#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int N, D, k = 0;
    std::cin >> N >> D;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(D));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int m = 0;
            for (int n = 0; n < D; n++) {
                m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
            }
            double l = sqrt(m);
            if (ceil(l) == floor(l)) k++;
        }
    }

    std::cout << k << std::endl;
    return 0;
}

// <END-OF-CODE>
