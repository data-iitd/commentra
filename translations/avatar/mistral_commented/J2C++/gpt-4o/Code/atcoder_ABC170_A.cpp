// Importing necessary C++ libraries for reading input and writing output
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    // Creating a string to read input from the console
    std::string input_line;
    
    // Reading input line from the console
    std::getline(std::cin, input_line);
    
    // Creating a string stream to parse the input line
    std::istringstream iss(input_line);
    std::string str;
    
    // Initializing result variable to 0
    int result = 0;

    // Iterating through each string in the input line
    while (iss >> str) {
        // Incrementing result variable for each non-zero string encountered
        result++;

        // Breaking the loop if a zero string is encountered
        if (str == "0") break;
    }

    // Writing the result to the console
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
