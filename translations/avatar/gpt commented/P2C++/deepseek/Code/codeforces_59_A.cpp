#include <iostream>
#include <string>

int main() {
    std::string txt;
    std::cin >> txt;

    int cu = 0;  // Counter for uppercase letters
    int cl = 0;  // Counter for lowercase letters

    // Iterate through each character in the input text
    for (char z : txt) {
        // Check if the character is lowercase
        if (islower(z)) {
            cl = cl + 1;  // Increment lowercase counter
        } else {
            cu = cu + 1;  // Increment uppercase counter
        }
    }

    // Compare the counts of uppercase and lowercase letters
    if (cu > cl) {
        // If there are more uppercase letters, convert the text to uppercase
        for (char &z : txt) {
            z = toupper(z);
        }
    } else {
        // If there are more lowercase letters or they are equal, convert the text to lowercase
        for (char &z : txt) {
            z = tolower(z);
        }
    }

    // Print the resulting output
    std::cout << txt << std::endl;

    return 0;
}
