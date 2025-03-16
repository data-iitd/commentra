#include <iostream> // Including iostream for input and output operations
#include <sstream>  // Including sstream for string stream operations
#include <string>   // Including string for string manipulations

int main() { // Main function where execution begins
    try { // Beginning of try block to handle potential exceptions
        std::string input; // Declaring a string to hold input
        std::getline(std::cin, input); // Reading a line of input from standard input
        std::istringstream iss(input); // Creating a string stream from the input string
        int a, b; // Declaring integers a and b
        iss >> a >> b; // Extracting integers a and b from the string stream
        int c = a - b * 2; // Performing a mathematical operation to calculate a result
        if (c < 0) c = 0; // Checking if the result is negative and setting it to 0 if true
        std::cout << c << std::endl; // Printing the result to the standard output
    } catch (...) { // Catch block to handle exceptions
        // Handle exceptions (not implemented in this code)
    }
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
