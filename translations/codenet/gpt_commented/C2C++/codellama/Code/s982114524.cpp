#include <iostream>

int main() {
    // Declare variables
    int i, N, x;
    x = 0; // Initialize x to 0 to hold the sum

    // Read an integer N from user input
    std::cin >> N;

    // Loop from 1 to N to calculate the sum of integers
    for(i = 1; i <= N; i++) {
        x += i; // Add the current value of i to x
    }

    // Print the calculated sum
    std::cout << x << std::endl;

    return 0; // Indicate that the program ended successfully
}

