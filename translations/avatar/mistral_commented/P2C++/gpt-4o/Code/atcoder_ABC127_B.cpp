#include <iostream>
#include <cmath> // For round function

int main() {
    // Take three integers as input from the user
    int r, D, x;
    std::cin >> r >> D >> x;

    // Iterate through the range of numbers from 2 to 11 (12 is excluded)
    for (int i = 2; i < 12; ++i) {
        // Calculate the expression and print the integer result
        int result = static_cast<int>(std::round((std::pow(r, i - 1)) * (x + D / (1 - r)) - D / (1 - r)));
        std::cout << result << std::endl;
    }

    return 0;
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)

