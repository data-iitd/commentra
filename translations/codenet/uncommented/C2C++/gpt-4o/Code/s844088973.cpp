#include <iostream>

int main() {
    int K, X;
    std::cin >> K >> X;
    for (int i = X - K + 1; i <= X + K - 1; i++) {
        std::cout << i;
        if (i < X + K - 1) std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}

// <END-OF-CODE>
