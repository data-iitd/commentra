#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    // Define the difference between lowercase and uppercase ASCII values
    char d = 'a' - 'A';

    // Iterate over each character in the input string
    for (char r : s) {
        char rr = r;
        // Check if the character is an uppercase letter
        if ('A' <= r && r <= 'Z') {
            // Convert uppercase to lowercase
            rr = r + d;
        } else if ('a' <= r && r <= 'z') {
            // Convert lowercase to uppercase
            rr = r - d;
        }
        // Print the converted character
        std::cout << rr;
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
