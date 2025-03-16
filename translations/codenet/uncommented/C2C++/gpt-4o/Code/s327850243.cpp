#include <iostream>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> A(m, std::vector<int>(n));
    std::vector<int> B(n);
    std::vector<int> S(m, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            S[i] += A[i][j] * B[j];
        }
    }

    for (int i = 0; i < m; i++) {
        std::cout << S[i] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
