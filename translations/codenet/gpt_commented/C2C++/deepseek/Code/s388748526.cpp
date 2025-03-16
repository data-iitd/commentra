#include <iostream>  // Include iostream library for input-output stream
#include <cmath>     // Include cmath library for mathematical constants and functions

int main() {
    double r;  // Declare a variable to store the radius

    // Prompt the user to input the radius
    std::cout << "Enter the radius: ";
    std::cin >> r;  // Read the radius from user input

    // Calculate and print the area and circumference of the circle
    // Area = π * r^2
    // Circumference = 2 * π * r
    std::cout << r * r * M_PI << " " << 2 * M_PI * r << std::endl;

    return 0;  // Return 0 to indicate successful execution
}

