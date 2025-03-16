#include <iostream>

int main() {
    // Declare four integer variables to hold input values
    int a, b, c, d;

    // Read four integers from user input
    std::cin >> a >> b >> c >> d;

    // Compare the sum of the first two integers (a and b) with the sum of the last two integers (c and d)
    if (a + b > c + d) {
        // If the sum of a and b is greater, print "Left"
        std::cout << "Left" << std::endl;
    } else if (a + b < c + d) {
        // If the sum of a and b is less, print "Right"
        std::cout << "Right" << std::endl;
    } else {
        // If both sums are equal, print "Balanced"
        std::cout << "Balanced" << std::endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
