#include <iostream>

int main() {
    // Declare three integer variables to store input values
    int a, b, c;
    
    // Read three integers from standard input and assign them to a, b, and c
    std::cin >> a >> b >> c;
    
    // Check if a is less than b and b is less than c
    if (a < b && b < c) {
        // If the condition is true, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // Otherwise, print "No"
        std::cout << "No" << std::endl;
    }
    
    // Return from the function
    return 0;
}

// <END-OF-CODE>
