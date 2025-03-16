
#include <iostream>
#include <string>

int main() {
    // Get the text input from the user
    std::string txt;
    std::getline(std::cin, txt);

    // Initialize the count of uppercase and lowercase characters
    int cu = 0;
    int cl = 0;

    // Iterate through each character in the text input
    for (char z : txt) {
        // If the character is lowercase, increment the lowercase count
        if (std::islower(z)) {
            cl++;
        }
        // If the character is uppercase, increment the uppercase count
        else {
            cu++;
        }
    }

    // Determine the output based on the count of uppercase and lowercase characters
    std::string out;
    if (cu > cl) {
        // If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
        out = txt;
        for (char &z : out) {
            z = std::toupper(z);
        }
    }
    else {
        // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
        out = txt;
        for (char &z : out) {
            z = std::tolower(z);
        }
    }

    // Print the output
    std::cout << out << std::endl;

    return 0;
}
