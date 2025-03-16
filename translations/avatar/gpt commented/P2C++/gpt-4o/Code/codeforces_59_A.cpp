#include <iostream>
#include <string>

int main() {
    // Get input from the user
    std::string txt;
    std::getline(std::cin, txt);

    // Initialize counters for uppercase and lowercase letters
    int cu = 0;  // Counter for uppercase letters
    int cl = 0;  // Counter for lowercase letters

    // Iterate through each character in the input text
    for (char z : txt) {
        // Check if the character is lowercase
        if (std::islower(z)) {
            cl++;  // Increment lowercase counter
        } else if (std::isupper(z)) {
            cu++;  // Increment uppercase counter
        }
    }

    // Compare the counts of uppercase and lowercase letters
    std::string out;
    if (cu > cl) {
        // If there are more uppercase letters, convert the text to uppercase
        for (char z : txt) {
            out += std::toupper(z);
        }
    } else {
        // If there are more lowercase letters or they are equal, convert the text to lowercase
        for (char z : txt) {
            out += std::tolower(z);
        }
    }

    // Print the resulting output
    std::cout << out << std::endl;

    return 0;
}

// <END-OF-CODE>
