// Import the necessary header for input and output
#include <iostream>

int main() {
    // Declare and initialize two integer variables, a and b
    int a, b;
    std::cin >> a >> b;

    // Check if the product of a and b is even using the modulo operator (%).
    // If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
    if (a * b % 2 == 0) {
        // If the condition is true, print the message "Even"
        std::cout << "Even" << std::endl;
    } else {
        // If the condition is false, print the message "Odd"
        std::cout << "Odd" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
