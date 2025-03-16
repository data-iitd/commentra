#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Read a line from input
    std::string input_string;
    std::getline(std::cin, input_string);

    // Replace all commas with spaces in the input string
    std::replace(input_string.begin(), input_string.end(), ',', ' ');

    // Print the modified string to the console
    std::cout << input_string << std::endl;

    return 0;
}

// <END-OF-CODE>
