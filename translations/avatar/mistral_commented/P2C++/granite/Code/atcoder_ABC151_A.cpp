
#include <iostream>
#include <string>
#include <vector>

// Define a function to log messages when debug mode is enabled
void log(std::string text) {
    // Check if debug mode is enabled
    if (debug) {
        // Print the log message
        std::cout << text << std::endl;
    }
}

// Function to parse input lines
std::vector<std::string> parse_input(std::string lines_as_string = "") {
    // Set the global debug flag
    global debug;

    // Initialize an empty vector to store the lines
    std::vector<std::string> lines;

    // If lines_as_string is provided, set debug mode to true and parse lines
    if (!lines_as_string.empty()) {
        debug = true;
        lines = {e for e in lines_as_string.split("\n")};
        lines.erase(lines.begin());
        lines.pop_back();
    }

    // Extract the first character from the first line as the command
    std::string c = lines[0].substr(0, 1);

    // Return the command as a tuple
    return {c};
}

// Function to solve the problem based on the command
std::string solve(std::string c) {
    // Define the alphabet string
    std::string a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = a.find(c);

    // Return the next character in the alphabet string
    return a.substr(i + 1, 1);
}

// Main function to execute the code
int main() {
    // Call the parse_input function to get the command
    std::vector<std::string> result = solve(parse_input()[0]);

    // Check if the result is a list or a single string
    if (result.size() > 1) {
        // If it's a list, print each element separately
        for (const auto& r : result) {
            std::cout << r << std::endl;
        }
    } else {
        // If it's a single string, print it directly
        std::cout << result[0] << std::endl;
    }

    return 0;
}

// End of code