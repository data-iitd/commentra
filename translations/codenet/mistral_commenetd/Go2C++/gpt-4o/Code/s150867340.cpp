// Import the necessary header for input and output
#include <iostream>

int main() {
    // Declare and initialize two integer variables "a" and "b"
    int a, b;
    // Read input values from the standard input
    std::cin >> a >> b;

    // Calculate the product of "a" and "b"
    int product = a * b;

    // Check if the product is even or odd using an if statement
    if (product % 2 == 0) {
        // If the product is even, print the message "Even" to the standard output
        std::cout << "Even" << std::endl;
    } else {
        // If the product is odd, print the message "Odd" to the standard output
        std::cout << "Odd" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
