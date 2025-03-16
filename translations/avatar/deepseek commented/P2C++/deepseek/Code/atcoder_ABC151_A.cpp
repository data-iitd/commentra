#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool debug = false;

void log(const std::string& text) {
    if (debug) {
        std::cout << text << std::endl;
    }
}

// Function to parse input from either user input or a string
std::vector<std::string> parse_input(const std::string& lines_as_string = "") {
    std::vector<std::string> lines;
    if (lines_as_string.empty()) {
        debug = false;
        std::string input;
        std::getline(std::cin, input);
        lines.push_back(input);
    } else {
        debug = true;
        std::stringstream ss(lines_as_string);
        std::string line;
        while (std::getline(ss, line, '\n')) {
            if (!line.empty() && line[0] == '[' && line[line.size() - 1] == ']') {
                lines.push_back(line.substr(1, line.size() - 2));
            }
        }
    }
    std::vector<std::string> result;
    std::stringstream ss(lines[0]);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        result.push_back(token);
    }
    return {result[0]};
}

// Function to solve the problem by finding the next character in the alphabet
std::string solve(const std::string& c) {
    std::string a = "abcdefghijklmnopqrstuvwxyz";
    size_t i = a.find(c);
    if (i != std::string::npos && i < a.size() - 1) {
        return std::string(1, a[i + 1]);
    }
    return "";
}

// Main function to orchestrate the execution of the program
int main() {
    std::string result = solve(parse_input()[0]);
    if (!result.empty()) {
        std::cout << result << std::endl;
    }
    return 0;
}

