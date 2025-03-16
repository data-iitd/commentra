#include <iostream>

int main() {
    // Declare three integer variables x, a, and b to store input values.
    int x, a, b;
    
    // Read three integers from the standard input and assign them to x, a, and b.
    std::cin >> x >> a >> b;
    
    // Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
    if (b - a <= 0) {
        // If b-a is less than or equal to 0, print "delicious".
        std::cout << "delicious" << std::endl;
    } else if (b - a <= x) {
        // If b-a is greater than 0 but less than or equal to x, print "safe".
        std::cout << "safe" << std::endl;
    } else {
        // If b-a is greater than x, print "dangerous".
        std::cout << "dangerous" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
