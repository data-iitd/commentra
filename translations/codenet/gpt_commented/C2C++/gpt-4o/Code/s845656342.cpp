#include <iostream> // Include input-output stream library

int main() // Main function where execution starts
{
    int x; // Declare an integer variable x

    // Read an integer value from user input and store it in x
    std::cin >> x;

    // Check if the value of x is equal to 1
    if (x == 1) 
        std::cout << "0" << std::endl; // If x is 1, print "0"
    else 
        std::cout << "1" << std::endl; // If x is not 1, print "1"

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
