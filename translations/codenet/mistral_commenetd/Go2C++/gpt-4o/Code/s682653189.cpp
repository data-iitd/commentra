#include <iostream>
#include <string>

int main() {
    // Initialize a variable "s" of type string.
    std::string s;

    // Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
    std::cin >> s;

    // Iterate through each character in the string "s" using a for loop.
    for (size_t i = 0; i < s.length(); i++) {
        // Print the character 'x' for each character in the string "s".
        std::cout << "x";
    }

    // Print a newline character to the standard output.
    std::cout << std::endl;

    // Indicate the end of the code.
    return 0;
}

// <END-OF-CODE>
