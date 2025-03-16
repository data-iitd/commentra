#include <iostream>  // Including iostream for input and output operations
#include <sstream>   // Including sstream for string stream operations
#include <vector>    // Including vector for dynamic array

int main() {
    std::string input;  // Declaring a string to hold the input
    std::getline(std::cin, input);  // Reading a line of input

    std::istringstream iss(input);  // Creating a string stream from the input
    std::string str;  // Declaring a string to hold each token
    int result = 0;   // Initializing a variable to store the count of non-zero elements

    // Iterating through the input tokens
    while (iss >> str) {
        result += 1;  // Incrementing the result for each element
        if (str == "0") break;  // Breaking the loop if a zero is encountered
    }

    std::cout << result << std::endl;  // Printing the result to the console
    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
