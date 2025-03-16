#include <iostream>

int main() {
    // Declare two integer variables x and y
    int x = 0, y = 0;

    // Read two integers from the user using cin and store them in variables x and y respectively
    std::cin >> x >> y;

    // Print the product of x and y and the sum of 2 times x and 2 times y using cout
    std::cout << (x * y) << " " << (2 * x + 2 * y) << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
