// Importing required packages
#include <iostream>
#include <string>

int main() {
    // Initializing a string 's' for storing input
    std::string s;

    // Reading the first line from standard input and storing it in the string 's'
    std::getline(std::cin, s);

    // Declaring and initializing a variable 'd' with the value of 'a' - 'A'
    int d = 'a' - 'A';

    // Iterating through each character 'r' in the string 's'
    for (char& r : s) {
        // Declaring and initializing a variable 'rr' with the value of 'r'
        char rr = r;

        // Checking if the current character 'r' is an uppercase letter
        if ('A' <= r && r <= 'Z') {
            // If yes, adding the value of 'd' to 'r' and storing it in 'rr'
            rr = r + d;
        } else if ('a' <= r && r <= 'z') {
            // If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
            rr = r - d;
        }

        // Printing the transformed character 'rr' to the standard output
        std::cout << rr;
    }

    // Printing a newline character after the transformation is complete
    std::cout << std::endl;

    // End of the code
    return 0;
}
