#include <iostream>

// Declare global variables for storing two integers
int x, y;

int main() {
    // Read two integers from user input
    std::cin >> x >> y;
    
    // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    // Print the results: product and perimeter
    std::cout << (x * y) << " " << (2 * x + 2 * y) << std::endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
