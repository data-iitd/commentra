
#include <iostream>  // Include the standard input/output stream library
#include <cmath>  // Include the mathematical functions library

int main() {
    int n;  // Declare an integer variable to store the input value
    std::cin >> n;  // Read an integer input from the user

    int x = 1;  // Initialize a counter variable to track the number of iterations

    while (std::log2(n) % 1) {  // Continue looping while n is not a power of 2
        x++;  // Increment the counter for each iteration
        // Subtract the largest power of 2 less than or equal to n from n
        n -= std::pow(2, std::floor(std::log2(n)));
    }

    std::cout << x << std::endl;  // Print the final count of iterations

    return 0;  // Return a success status
}

