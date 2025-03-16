
#include <iostream> // Include the standard input/output library

int main() { // Define the main function, the entry point of the program
    int x, y; // Declare two integer variables to store user input
    std::cin >> x >> y; // Read two integers from the standard input and store them in x and y
    std::cout << x * y << " " << 2 * x + 2 * y << std::endl; // Print the product of x and y and the perimeter of the rectangle
    return 0; // Return 0 to indicate successful execution
}
