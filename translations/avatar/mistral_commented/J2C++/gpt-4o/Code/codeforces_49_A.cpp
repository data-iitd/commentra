#include <iostream>
#include <string>
#include <cctype>

int main() {
    // Initialize a string to store the input line
    std::string s;

    // Read the next line from the console and store it in the string 's'
    std::getline(std::cin, s);

    // Get the length of the string 's'
    int length = s.length();

    // Initialize a character variable 'ch' to store the first non-space and non-question mark character found in the string 's'
    char ch = ' ';

    // Iterate through the string 's' from the end to the beginning
    for (int i = length - 1; i >= 0; i--) {
        // Check if the current character is not a space or a question mark
        if (s[i] != ' ' && s[i] != '?') {
            // If yes, store the character in 'ch' and break out of the loop
            ch = s[i];
            break;
        }
    }

    // Convert the character 'ch' to lowercase
    ch = std::tolower(ch);

    // Check if the character 'ch' is a vowel or a y
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        // If yes, print "YES" to the console
        std::cout << "YES" << std::endl;
    } else {
        // If no, print "NO" to the console
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
