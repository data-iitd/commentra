#include <iostream>
#include <cmath>

int main() {
    // Read three integers r, D, and x from input
    int r, D, x;
    std::cin >> r >> D >> x;

    // Loop from 2 to 11 (inclusive)
    for (int i = 2; i <= 11; ++i) {
        // Calculate the value using the given formula and print the integer result
        int result = static_cast<int>((pow(r, i - 1) * (x + static_cast<double>(D) / (1 - r)) - static_cast<double>(D) / (1 - r)));
        std::cout << result << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
