// Importing required headers
#include <iostream>
#include <string>
#include <sstream>

// Initializing variables
std::istream& reader = std::cin;
std::ostream& writer = std::cout;

// Function to read input
std::string readInput() {
    std::string input;
    std::getline(reader, input);
    return input;
}

// Function to write output
void writeOutput(const std::string& output) {
    writer << output;
}

int main() {
    // Example usage
    std::string input = readInput();
    writeOutput(input);
    
    return 0;
}

// <END-OF-CODE>
