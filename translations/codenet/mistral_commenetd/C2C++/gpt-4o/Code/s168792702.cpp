#include <iostream>

// Include the iostream library for input/output

int main() {
    // Declare three integer variables: a, b, and c
    int a, b, c;

    // Use the cin object to read three integers from the standard input and store them in variables a, b, and c
    std::cin >> a >> b >> c;

    // Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output. Otherwise, print "No"
    if (a < b && b < c) {
        std::cout << "Yes" << std::endl; // If the condition is true, print "Yes"
    } else {
        std::cout << "No" << std::endl; // If the condition is false, print "No"
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
