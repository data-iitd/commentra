#include <iostream>
#include <cmath>  // Include the cmath library for mathematical functions

int main() {
    // Read an integer input from the user
    int n;
    std::cin >> n;

    // Initialize a counter variable to track the number of iterations
    int x = 1;

    // Continue looping while n is not a power of 2
    while (std::log2(n) - static_cast<int>(std::log2(n)) != 0) {
        x++;  // Increment the counter for each iteration
        // Subtract the largest power of 2 less than or equal to n from n
        n -= static_cast<int>(std::pow(2, static_cast<int>(std::log2(n))));
    }

    // Print the final count of iterations
    std::cout << x << std::endl;

    return 0;
}

// <END-OF-CODE>
