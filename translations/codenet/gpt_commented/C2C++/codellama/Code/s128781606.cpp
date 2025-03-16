#include <iostream>

int main() {
    // Declare variables to hold input values and results
    int A, B, C, D, E, max;

    // Read two integers from user input
    std::cin >> A >> B;

    // Calculate the sum, difference, and product of A and B
    C = A + B;  // Sum of A and B
    D = A - B;  // Difference of A and B
    E = A * B;  // Product of A and B

    // Initialize max with the value of C (sum)
    max = C;

    // Compare max with D (difference) and update if D is greater
    if (max < D) {
        max = D;
    }

    // Compare max with E (product) and update if E is greater
    if (max < E) {
        max = E;
    }

    // Print the maximum value among sum, difference, and product
    std::cout << max << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

