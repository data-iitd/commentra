#include <iostream> // Include the iostream library for input and output

int main() {
    int a, b; // Declare two integer variables 'a' and 'b'
    // Initialize them to zero by default

    std::cin >> a; // Read an integer value from the standard input and store it in variable 'a'
    std::cin >> b; // Read an integer value from the standard input and store it in variable 'b'

    if ((a * b) % 2 == 0) { // Check if the product of 'a' and 'b' is even
        std::cout << "Even" << std::endl; // If it is even, print "Even" to the standard output
    } else {
        std::cout << "Odd" << std::endl; // If it is odd, print "Odd" to the standard output
    }

    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
