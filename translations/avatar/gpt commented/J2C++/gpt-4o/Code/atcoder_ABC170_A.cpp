#include <iostream>
#include <sstream>
#include <vector>

int main() {
    // Create a string to read the entire line of input
    std::string input_line;
    
    // Read a line of input from the standard input stream
    std::getline(std::cin, input_line);
    
    // Use a stringstream to split the input line into words
    std::stringstream ss(input_line);
    std::string str;
    
    // Initialize a counter to keep track of the number of non-zero inputs
    int result = 0;
    
    // Iterate through each string in the input
    while (ss >> str) {
        // Increment the counter for each input
        result += 1;
        
        // If the input is "0", break out of the loop
        if (str == "0") break;
    }
    
    // Print the result, which is the count of non-zero inputs before the first "0"
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
