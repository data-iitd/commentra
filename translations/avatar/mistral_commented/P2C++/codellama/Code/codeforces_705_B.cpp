#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int w[n];
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    int c = 2;
    for (int i = 0; i < n; i++) {
        if (w[i] == 1) {
            std::cout << c << std::endl;
        } else if (w[i] % 2 == 0) {
            c = 3 - c;
            std::cout << c << std::endl;
        } else {
            std::cout << c << std::endl;
        }
    }

    return 0;
}

