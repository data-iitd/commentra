#include <iostream>

int main() {
    // Declare three integer variables a, b, and c
    int a, b, c;
    
    // Read input values for a, b, and c from the user
    std::cin >> a >> b >> c;

    // Check if c is within the range [a, b]
    if (c >= a && c <= b) {
        // If c is within the range, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // If c is outside the range, print "No"
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
