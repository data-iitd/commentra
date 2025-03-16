#include <iostream> // Standard Input/Output library
#include <cstdlib>  // Standard Library for memory allocation and other functions
#include <limits>   // Library for working with maximum and minimum values
#include <cmath>    // Library for mathematical functions

int main() {
    // Declare variables
    int n;

    std::cout << "Enter the value of n: ";
    std::cin >> n; // Read an integer value from the user and store it in variable n

    // Calculate and print the result
    std::cout << "The result is: " << (24 + (24 - n)) << std::endl;

    return 0; // Indicate successful execution of the program
}

// <END-OF-CODE>
