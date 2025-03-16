#include <iostream>
#include <iomanip>

int main() {
    // Step 2: Declare variables to store the radius, area, and circumference of the circle.
    double r;
    double s, l;
    
    // Step 4: Initialize the value of π (pi) to a constant.
    const double p = 3.141592653589;
    
    // Step 5: Read the radius from the user.
    std::cin >> r;
    
    // Step 6: Calculate the area of the circle using the formula: area = π * radius^2.
    s = r * r * p;
    
    // Step 7: Calculate the circumference of the circle using the formula: circumference = 2 * π * radius.
    l = 2 * p * r;
    
    // Step 8: Print the area and circumference of the circle.
    std::cout << std::fixed << std::setprecision(6) << s << " " << l << std::endl;
    
    // Step 9: Return 0 to indicate successful execution of the program.
    return 0;
}

// <END-OF-CODE>
