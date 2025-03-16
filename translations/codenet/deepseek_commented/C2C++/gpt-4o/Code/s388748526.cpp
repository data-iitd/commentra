#include <iostream>
#include <cmath>

int main() {
    // This code uses the standard input/output library and the cmath library for mathematical constants and functions

    double r;
    // Read the input value for the radius of the circle
    std::cin >> r;

    // Calculate the area of the circle (πr^2) and the circumference (2πr)
    double area = r * r * M_PI;
    double circumference = 2 * M_PI * r;

    // Print the results to the standard output
    std::cout << area << " " << circumference << std::endl;
    return 0;
}

// <END-OF-CODE>
