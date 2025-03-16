
// Include necessary libraries
#include <iostream>
#include <string>
#include <sstream>

// Initialize input and output streams
int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        // Process each word
    }
    return 0;
}

