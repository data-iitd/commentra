#include <iostream>
#include <string>
#include <cctype> // for tolower function

int main() {
    std::string s;
    std::getline(std::cin, s); // Read a line of input from the user and store it in a string variable s
    char ch = 0; // Initialize a character variable ch to 0

    // Iterate through the string s in reverse order, starting from the last character
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '?') { // Check if the current character is not a space or a question mark
            ch = s[i]; // Assign the current character to the variable ch
            break; // Exit the loop
        }
    }

    ch = std::tolower(ch); // Convert the character ch to lowercase

    // Check if ch is one of the vowels (a, e, i, o, u, y)
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        std::cout << "YES" << std::endl; // Print "YES" if ch is a vowel
    } else {
        std::cout << "NO" << std::endl; // Print "NO" if ch is not a vowel
    }

    return 0;
}
