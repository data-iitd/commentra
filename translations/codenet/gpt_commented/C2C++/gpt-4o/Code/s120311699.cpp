#include <iostream>

int main() {
    // Declare three integer variables to hold the input values
    int a, b, c;

    // Read three integers from user input
    std::cin >> a >> b >> c;

    // Check if the first number is less than the second and the second is less than the third
    if (a < b && b < c) {
        // If the condition is true, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print "No"
        std::cout << "No" << std::endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
