#include <iostream>

int main() {
    // Declare variables K and X to hold input values
    int K, X;
    
    // Read two integers from standard input
    std::cin >> K >> X;
    
    // Check if 500 times K is greater than or equal to X
    if (500 * K >= X) {
        // If the condition is true, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print "No"
        std::cout << "No" << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
