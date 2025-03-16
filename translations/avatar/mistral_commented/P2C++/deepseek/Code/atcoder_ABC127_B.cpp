#include <iostream>
#include <cmath> // Include the cmath library for the pow and round functions

int main() {
    int r, D, x;
    // Take three integers as input from the user
    std::cin >> r >> D >> x;

    // Iterate through the range of numbers from 2 to 11 (12 is excluded)
    for (int i = 2; i < 12; ++i) {
        // Calculate the expression and print the integer result
        double result = pow(r, i - 1) * (x + D / (1 - r)) - D / (1 - r);
        std::cout << static_cast<int>(round(result)) << std::endl;
    }

    return 0;
}
