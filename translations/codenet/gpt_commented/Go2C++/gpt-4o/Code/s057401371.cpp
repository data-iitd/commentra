#include <iostream>
#include <string>

int main() {
    // Read a line of input
    std::string s;
    std::getline(std::cin, s);

    // Calculate the difference between lowercase and uppercase letters
    char d = 'a' - 'A';

    // Iterate over each character in the input string
    for (char r : s) {
        // Initialize a variable to hold the modified character
        char rr = r;

        // Check if the character is an uppercase letter
        if ('A' <= r && r <= 'Z') {
            // Convert uppercase to lowercase by adding the difference
            rr = r + d;
        } else if ('a' <= r && r <= 'z') {
            // Convert lowercase to uppercase by subtracting the difference
            rr = r - d;
        }

        // Print the modified character
        std::cout << rr;
    }

    // Print a newline at the end of the output
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
