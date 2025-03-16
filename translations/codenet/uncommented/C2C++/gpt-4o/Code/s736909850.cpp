#include <iostream>

int main() {
    int sheep;
    int wolf;

    std::cin >> sheep >> wolf;

    if (wolf >= sheep) {
        std::cout << "unsafe" << std::endl;
    } else {
        std::cout << "safe" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
