#include <iostream>  // Include the iostream library for input/output
#include <cstdlib>   // Include the cstdlib library for memory allocation
#include <cmath>     // Include the cmath library for square root calculation

int main()  // The main function is the entry point of the program
{
    int x;  // Declare an integer variable named x

    // Read an integer value from the standard input and store it in the variable x
    std::cin >> x;

    if (x == 1)  // Check if the value of x is equal to 1
    {
        std::cout << "0" << std::endl;  // If x is 1, print 0 to the standard output
    }
    else  // If x is not equal to 1
    {
        std::cout << "1" << std::endl;  // Otherwise, print 1 to the standard output
    }

    return 0;  // Indicate that the program has run successfully and terminate
}

// <END-OF-CODE>
