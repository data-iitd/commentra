#include <iostream>

int main() {
    int a, b, c, i, j, k;
    int max;

    std::cin >> j;

    for (i = 0; i < j; i++) {
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;

        max = a;
        k = 0;
        if (max <= b) {
            max = b;
            k = 1;
        }
        if (max <= c) {
            max = c;
            k = 2;
        }

        max = max * max;
        a = a * a;
        b = b * b;
        c = c * c;
        if (k == 0 && max == b + c) {
            std::cout << "YES" << std::endl;
        } else if (k == 1 && max == a + c) {
            std::cout << "YES" << std::endl;
        } else if (k == 2 && max == a + b) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
