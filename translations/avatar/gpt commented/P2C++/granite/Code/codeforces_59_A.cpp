
#include <iostream>
#include <string>

int main() {
    std::string txt;
    std::cout << "Enter a text: ";
    std::getline(std::cin, txt);

    int cu = 0;  // Counter for uppercase letters
    int cl = 0;  // Counter for lowercase letters

    // Iterate through each character in the input text
    for (char z : txt) {
        // Check if the character is lowercase
        if (std::islower(z)) {
            cl++;  // Increment lowercase counter
        } else {
            cu++;  // Increment uppercase counter
        }
    }

    std::string out;
    // Compare the counts of uppercase and lowercase letters
    if (cu > cl) {
        // If there are more uppercase letters, convert the text to uppercase
        out = txt;
        for (char &z : out) {
            z = std::toupper(z);
        }
    } else {
        // If there are more lowercase letters or they are equal, convert the text to lowercase
        out = txt;
        for (char &z : out) {
            z = std::tolower(z);
        }
    }

    // Print the resulting output
    std::cout << out << std::endl;

    return 0;
}
