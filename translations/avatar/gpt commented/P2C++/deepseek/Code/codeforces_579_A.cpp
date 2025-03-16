#include <iostream>
#include <cmath>  // Include the cmath library to use mathematical functions

int main() {
    int n;
    std::cin >> n;  // Read an integer input from the user

    int x = 1;  // Initialize a counter variable to track the number of iterations

    // Continue looping while n is not a power of 2
    while (std::fmod(std::log2(n), 1) != 0) {
        x += 1;  // Increment the counter for each iteration
        // Subtract the largest power of 2 less than or equal to n from n
        n -= std::pow(2, static_cast<int>(std::log2(n)));
    }

    // Print the final count of iterations
    std::cout << x << std::endl;

    return 0;
}
