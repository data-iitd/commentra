#include <iostream>

int main() {
    int a, b, c;

    std::cin >> a >> b >> c;

    if (b > a * c) {
        std::cout << c << std::endl;
    } else {
        std::cout << b / a << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
