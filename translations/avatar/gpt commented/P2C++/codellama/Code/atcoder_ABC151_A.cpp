
#include <iostream>
#include <string>

// Flag to enable or disable debugging
bool debug = false;

// Function to log debug messages
void log(std::string text) {
    if (debug) {
        std::cout << text << std::endl;
    }
}

// Function to parse input from the user or from a string
std::string parse_input(std::string lines_as_string = "") {
    std::string lines = "";
    
    // Check if input is provided as a string
    if (lines_as_string == "") {
        debug = false;  // Disable debug mode for standard input
        std::getline(std::cin, lines);  // Read input from the user
    } else {
        debug = true;  // Enable debug mode for string input
        // Split the input string into lines and ignore the first and last lines
        lines = lines_as_string.substr(1, lines_as_string.length() - 2);
    }
    
    // Extract the first element from the first line as the character to process
    std::string c = lines.substr(0, lines.find(" "));
    return c;
}

// Function to solve the problem by finding the next character in the alphabet
std::string solve(std::string c) {
    std::string a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    int i = a.find(c);  // Find the index of the given character
    return a.substr(i + 1, 1);  // Return the next character in the alphabet
}

// Main function to execute the program logic
void main() {
    // Parse input and solve the problem
    std::string result = solve(parse_input());
    
    // Check if the result is a list and print each result
    if (result.find(" ") != std::string::npos) {
        std::string r = "";
        while (result.find(" ") != std::string::npos) {
            r = result.substr(0, result.find(" "));
            std::cout << r << std::endl;
            result = result.substr(result.find(" ") + 1, result.length());
        }
        std::cout << result << std::endl;
    } else {
        // Print the single result
        std::cout << result << std::endl;
    }
}

// Entry point of the program
int main(int argc, char *argv[]) {
    main();
    return 0;
}

