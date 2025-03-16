#include <iostream>

int main() {
    // Declare variables to hold input values and loop counter
    int a, b, c, d, e, i;

    // Read three integers from user input
    std::cin >> a >> b >> c;

    // Check if b is less than or equal to c
    if (b <= c) {
        // If true, print "NO" and exit the program
        std::cout << "NO" << std::endl;
        return 0;
    } else {
        // Initialize d with the value of a
        d = a;

        // Calculate the remainder of d when divided by b
        e = d % b;

        // Loop through values from 0 to b-1
        for (i = 0; i < b; i++) {
            // Update d to be the remainder of d when divided by b
            d = d % b;

            // Check if d is equal to c
            if (d == c) {
                // If true, print "YES" and exit the program
                std::cout << "YES" << std::endl;
                return 0;
            } 
            // Check if this is not the first iteration and d is equal to c
            else if (i != 0 && d == c) {
                // If true, print "NO" and exit the program
                std::cout << "NO" << std::endl;
                return 0;
            }

            // Increment d by the value of a
            d += a;
        }
    }

    // If no conditions were met, print "NO"
    std::cout << "NO" << std::endl;
    return 0;
}

