#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Global debug flag
bool debug = false;

// Function to log messages when debug mode is enabled
void log(const std::string& text) {
    if (debug) {
        std::cout << text << std::endl;
    }
}

// Function to parse input lines
std::vector<std::string> parse_input(const std::string& lines_as_string) {
    // Initialize an empty vector to store the lines
    std::vector<std::string> lines;

    // Use a stringstream to split the input string by newline
    std::stringstream ss(lines_as_string);
    std::string line;

    // Read lines from the stringstream
    while (std::getline(ss, line)) {
        // Skip the first and last line
        if (!line.empty() && line != lines_as_string.substr(lines_as_string.size() - 1)) {
            lines.push_back(line);
        }
    }

    // Extract the first character from the first line as the command
    std::string command = lines[0];
    std::string c = command.substr(0, 1);

    // Return the command as a vector
    return {c};
}

// Function to solve the problem based on the command
std::string solve(const std::string& c) {
    // Define the alphabet string
    std::string a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    size_t i = a.find(c);

    // Return the next character in the alphabet string
    if (i != std::string::npos && i + 1 < a.size()) {
        return std::string(1, a[i + 1]);
    }

    // Return an empty string if the character is not found or out of bounds
    return "";
}

// Main function to execute the code
int main() {
    // Read input from stdin
    std::string input;
    std::getline(std::cin, input);

    // Call the parse_input function to get the command
    std::vector<std::string> result = parse_input(input);

    // Check if the result is a list or a single string
    if (!result.empty()) {
        // If it's a single string, print it directly
        std::cout << solve(result[0]) << std::endl;
    }

    return 0;
}
