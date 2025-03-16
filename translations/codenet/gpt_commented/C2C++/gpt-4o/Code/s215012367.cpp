#include <iostream>

int main() {
    // Declare variables to hold two integers and the result
    int a, b, s;

    // Read two integers from user input
    std::cin >> a >> b;

    // Calculate the result using the formula: (a*b) - (a + b) + 1
    s = (a * b) - (a + b) + 1;

    // Output the result to the console
    std::cout << s << std::endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
