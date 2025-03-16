#include <iostream>

int main() {
    // Declare two integer variables, K and X
    int K, X;

    // Read two integers from the standard input and assign them to the variables K and X respectively
    std::cin >> K >> X;

    // Check if the condition 500*K >= X is true
    if (500 * K >= X) {
        // If the condition is true, print the string "Yes" to the standard output
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print the string "No" to the standard output
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
