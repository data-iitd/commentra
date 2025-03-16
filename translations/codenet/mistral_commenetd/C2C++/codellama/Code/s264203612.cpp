
#include <iostream> // Include the standard input/output library

int main(){ // Start of the main function
    double r; // Declare a variable 'r' of type double
    double s, l; // Declare two variables 's' and 'l' of type double
    double p = 3.141592653589; // Initialize a constant variable 'p' with the value of pi

    std::cin >> r; // Read a value of type double from the standard input and store it in variable 'r'

    s = r*r*p; // Calculate the area of a circle with radius 'r' and store it in variable 's'
    l = 2*p*r; // Calculate the circumference of a circle with radius 'r' and store it in variable 'l'

    std::cout << s << " " << l << std::endl; // Print the values of 's' and 'l' to the standard output

    return 0; // End of the main function and return 0 to indicate successful execution
}

