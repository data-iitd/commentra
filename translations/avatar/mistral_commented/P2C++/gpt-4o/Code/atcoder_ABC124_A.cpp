#include <iostream>
#include <algorithm> // for std::max

int main() {
    // Get two integers as input from the user, separated by a space
    int a, b;
    std::cin >> a >> b;

    // Initialize a variable 'c' to store the sum of the larger numbers in each iteration
    int c = 0;

    // Loop through the given condition for 2 times
    for (int i = 0; i < 2; i++) {
        // Calculate the sum of the larger number in each iteration and add it to the variable 'c'
        c += std::max(a, b);

        // Update the smaller number in each iteration
        if (a >= b) {
            a -= 1;
        } else {
            b -= 1;
        }
    }

    // Print the final result
    std::cout << c << std::endl;

    return 0;
}

// <END-OF-CODE>
