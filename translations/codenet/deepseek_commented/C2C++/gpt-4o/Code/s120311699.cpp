#include <iostream>  // Include the iostream library for input and output

int main() {  // Define the main function, the entry point of the program
    int a, b, c;  // Declare three integer variables
    std::cin >> a >> b >> c;  // Read three integers from the standard input and store them in a, b, and c

    if (a < b && b < c) {  // Check if a is less than b and b is less than c
        std::cout << "Yes" << std::endl;  // If true, print "Yes"
    } else {  // Otherwise
        std::cout << "No" << std::endl;  // Print "No"
    }

    return 0;  // Return 0 to indicate successful execution of the program
}  // End of main function
// <END-OF-CODE>
