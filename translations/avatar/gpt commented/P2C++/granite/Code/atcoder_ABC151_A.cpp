
#include <iostream>
#include <string>
#include <vector>

// Flag to enable or disable debugging
bool debug = false;

// Function to log debug messages
void log(std::string text) {
    if (debug) {
        std::cout << text << std::endl;
    }
}

// Function to parse input from the user or from a string
std::vector<std::string> parse_input(std::string lines_as_string = "") {
    global debug;
    std::vector<std::string> lines;
    
    // Check if input is provided as a string
    if (lines_as_string.empty()) {
        debug = false;  // Disable debug mode for standard input
        std::getline(std::cin, lines[0]);  // Read input from the user
    } else {
        debug = true;  // Enable debug mode for string input
        // Split the input string into lines and ignore the first and last lines
        lines = {e for e in lines_as_string.split("\n")}[1:-1];
    }
    
    // Extract the first element from the first line as the character to process
    std::string c = lines[0].split(" ")[0];
    return {c};
}

// Function to solve the problem by finding the next character in the alphabet
std::string solve(std::string c) {
    std::string a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    int i = a.find(c);  // Find the index of the given character
    return a[i + 1];  // Return the next character in the alphabet
}

// Main function to execute the program logic
int main() {
    // Parse input and solve the problem
    std::vector<std::string> result = solve(parse_input()[0]);
    
    // Check if the result is a list and print each result
    if (result.size() > 1) {
        for (std::string r : result) {
            std::cout << r << std::endl;
        }
    } else {
        // Print the single result
        std::cout << result[0] << std::endl;
    }
    
    return 0;
}

// Entry point of the program
