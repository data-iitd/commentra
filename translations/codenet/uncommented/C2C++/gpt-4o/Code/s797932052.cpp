#include <iostream>

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;
    if ((a * b) % 2 == 0) {
        std::cout << "Even" << std::endl;
    } else {
        std::cout << "Odd" << std::endl;
    }
    return 0;
}

// <END-OF-CODE>
