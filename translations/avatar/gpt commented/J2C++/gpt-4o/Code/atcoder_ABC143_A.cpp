#include <iostream>
#include <sstream>
#include <string>

int main() {
    try {
        // Create a string to read input from the console
        std::string input;
        std::getline(std::cin, input);
        
        // Use a stringstream to parse the input
        std::istringstream iss(input);
        int a, b;
        
        // Read the first and second integers from the input
        iss >> a >> b;
        
        // Calculate the value of c based on the formula: c = a - b * 2
        int c = a - b * 2;
        
        // If c is negative, set it to 0
        if (c < 0) c = 0;
        
        // Output the final value of c
        std::cout << c << std::endl;
    } catch (...) {
        // Handle any exceptions that may occur during input or processing
    }
    return 0;
}

// <END-OF-CODE>
