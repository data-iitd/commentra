#include <iostream>
// Include the iostream library for input and output

int main() {
    // Declare the main function

    int a, b, c, d, i, j;
    // Declare variables a, b, c, d, i, and j

    std::cin >> a >> b >> c >> d;
    // Read four integers from the standard input and store them in variables a, b, c, and d

    i = a * b;
    // Multiply variables a and b and store the result in variable i

    j = c * d;
    // Multiply variables c and d and store the result in variable j

    if (i > j) {
        // Check if the value of i is greater than j

        std::cout << i << std::endl;
        // If true, print the value of i

    } else {
        // If the condition in the if statement is false

        std::cout << j << std::endl;
        // Print the value of j
    }

    return 0;
    // End the main function with a return value of 0
}

// <END-OF-CODE>
