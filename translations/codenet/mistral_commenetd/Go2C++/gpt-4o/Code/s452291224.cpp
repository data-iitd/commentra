#include <iostream>

int main() {
    // Declare variables A, B, and C of type int
    int A, B, C;

    // Read three integers from the standard input
    std::cin >> A >> B >> C;

    // Check if the condition C-A+B is less than zero
    if (C - A + B < 0) {
        // If the condition is true, print zero as output
        std::cout << "0" << std::endl;
    } else {
        // If the condition is false, calculate the value of C-A+B and print it as output
        std::cout << C - A + B << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
