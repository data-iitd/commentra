#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
    int X, A, B, C;
    int kosu = 0;

    // 整数の入力
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    std::cin >> X;

    X = X / 50;

    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k <= C; k++) {
                if (X == (10 * i) + (2 * j) + k) {
                    kosu++;
                }
            }
        }
    }

    std::cout << kosu << std::endl;

    return 0;
}

// <END-OF-CODE>
