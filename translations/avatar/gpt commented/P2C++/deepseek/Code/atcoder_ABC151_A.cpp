#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Flag to enable or disable debugging
bool debug = false;

// Function to log debug messages
void log(const std::string& text) {
    if (debug) {
        std::cout << text << std::endl;
    }
}

// Function to parse input from the user or from a string
std::vector<std::string> parse_input(const std::string& lines_as_string = "") {
    std::vector<std::string> lines;
    
    // Check if input is provided as a string
    if (lines_as_string.empty()) {
        debug = false;  // Disable debug mode for standard input
        std::string line;
        while (std::getline(std::cin, line)) {
            lines.push_back(line);  // Read input from the user
        }
    } else {
        debug = true;  // Enable debug mode for string input
        std::stringstream ss(lines_as_string);
        std::string line;
        while (std::getline(ss, line)) {
            lines.push_back(line);
        }
    }
    
    // Extract the first element from the first line as the character to process
    std::string c;
    std::stringstream ss(lines[0]);
    ss >> c;
    return {c};
}

// Function to solve the problem by finding the next character in the alphabet
std::string solve(const std::string& c) {
    std::string a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    size_t i = a.find(c);  // Find the index of the given character
    if (i != std::string::npos && i < a.size() - 1) {
        return std::string(1, a[i + 1]);  // Return the next character in the alphabet
    }
    return "";  // Return an empty string if the character is 'z'
}

// Main function to execute the program logic
int main() {
    // Parse input and solve the problem
    std::vector<std::string> result = solve(*parse_input());
    
    // Print the single result
    std::cout << result[0] << std::endl;

    return 0;
}
