#include <iostream>

int main() {
    // Declare integer variables to hold input values and results
    int a, b, c, d, i, j;

    // Read four integers from user input
    std::cin >> a >> b >> c >> d;

    // Calculate the product of the first two integers
    i = a * b;

    // Calculate the product of the last two integers
    j = c * d;

    // Compare the two products and print the larger one
    if (i > j) {
        // If the first product is greater, print it
        std::cout << i << std::endl;
    } else {
        // Otherwise, print the second product
        std::cout << j << std::endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
