#include <iostream>
#include <cmath>

int main() {
    // Take an integer input from the user and assign it to the variable n
    int n;
    std::cin >> n;

    // Initialize a counter variable x to 1
    int x = 1;

    // While loop starts
    while (true) {
        // Check if the log base 2 of n is an integer yet
        if (log2(n) == static_cast<int>(log2(n))) {
            break;
        }

        // Increment the counter variable x by 1
        x += 1;

        // Update the value of n by subtracting 2 raised to the power of the current log base 2 of n
        n -= static_cast<int>(pow(2, static_cast<int>(log2(n))));
    }

    // Print the output value of x
    std::cout << x << std::endl;

    return 0;
}

// <END-OF-CODE>
