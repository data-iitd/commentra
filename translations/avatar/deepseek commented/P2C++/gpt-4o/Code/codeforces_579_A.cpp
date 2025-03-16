#include <iostream>
#include <cmath>

int main() {
    // Take an integer input from the user
    int n;
    std::cin >> n;

    // Initialize a variable x to 1
    int x = 1;

    // Continue looping until the base-2 logarithm of n is an integer
    while (std::log2(n) - static_cast<int>(std::log2(n)) != 0) {
        // Increment x by 1
        x += 1;
        // Update n by subtracting 2 raised to the power of the integer part of the base-2 logarithm of n
        n -= static_cast<int>(std::pow(2, static_cast<int>(std::log2(n))));
    }

    // Print the value of x
    std::cout << x << std::endl;

    return 0;
}

// <END-OF-CODE>
