#include <iostream>
#include <algorithm> // for std::max

int main() {
    int a, b;
    std::cin >> a >> b;
    int c = 0;

    for (int i = 0; i < 2; i++) {
        c += std::max(a, b);
        if (a >= b) {
            a -= 1;
        } else {
            b -= 1;
        }
    }

    std::cout << c << std::endl;
    return 0;
}

// <END-OF-CODE>
