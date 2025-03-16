#include <iostream>

int main() {
    // Declare three integer variables A, B, and C
    int A, B, C;
    
    // Read input values for A, B, and C from the standard input
    std::cin >> A >> B >> C;

    // Check if the sum of A and B is greater than or equal to C
    if (A + B >= C) {
        // If the condition is true, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print "No"
        std::cout << "No" << std::endl;
    }

    return 0;
}
