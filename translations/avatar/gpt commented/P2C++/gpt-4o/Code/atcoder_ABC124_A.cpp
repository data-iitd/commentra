#include <iostream>
#include <algorithm> // for std::max

int main() {
    // Read two integers from input and assign them to variables a and b
    int a, b;
    std::cin >> a >> b;

    // Initialize a variable c to accumulate the result
    int c = 0;

    // Loop for 2 iterations
    for (int i = 0; i < 2; i++) {
        // Add the maximum of a and b to c
        c += std::max(a, b);
        
        // Decrease the larger of the two numbers (a or b) by 1
        if (a >= b) {
            a -= 1;  // If a is greater than or equal to b, decrement a
        } else {
            b -= 1;  // Otherwise, decrement b
        }
    }

    // Print the final accumulated value of c
    std::cout << c << std::endl;

    return 0;
}

// <END-OF-CODE>
