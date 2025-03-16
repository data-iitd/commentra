#include <iostream>
#include <string>

int main() {
    // Declare a string variable named "s"
    std::string s;

    // Use the "std::cin" function to read a string input from the standard input
    std::cin >> s;

    // Check if the length of the string "s" is greater than or equal to 4
    // and if its first four characters are "YAKI"
    if (s.length() >= 4 && s.substr(0, 4) == "YAKI") {
        // If the condition is true, print the word "Yes" to the standard output
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print the word "No" to the standard output
        std::cout << "No" << std::endl;
    }

    return 0;
}

