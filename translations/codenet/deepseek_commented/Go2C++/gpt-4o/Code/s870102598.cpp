#include <iostream>

int main() {
    // Declare three integer variables to hold the input values
    int a, b, c;
    
    // Read three integers from the standard input and assign them to a, b, and c
    std::cin >> a >> b >> c;
    
    // Check if c is between a and b (inclusive)
    if (c >= a && c <= b) {
        // If true, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // If false, print "No"
        std::cout << "No" << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
