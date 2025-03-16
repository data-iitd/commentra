#include <iostream> // Include the input/output stream library
#include <cmath>    // Include the mathematical library

int main() {
    double r; // Declare a variable named 'r' of type double

    // Read a value for 'r' from the standard input
    std::cin >> r;

    // Calculate the area and circumference of a circle with radius 'r'
    double area = r * r * M_PI;
    double circumference = 2 * M_PI * r;

    // Print the results to the standard output
    std::cout << area << " " << circumference << std::endl;

    // Indicate successful termination of the program
    return 0;
}

// <END-OF-CODE>
