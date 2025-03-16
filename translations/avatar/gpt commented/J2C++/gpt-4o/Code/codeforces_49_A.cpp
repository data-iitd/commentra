#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulation
#include <cctype>   // Include the cctype library for character handling

int main() {
    // Create a string variable to store user input
    std::string s;
    
    // Read a line of input from the user
    std::getline(std::cin, s);
    
    // Get the length of the input string
    int length = s.length();
    
    // Initialize a character variable to store the last non-space, non-question mark character
    char ch = 0;
    
    // Loop through the string in reverse to find the last relevant character
    for (int i = length - 1; i >= 0; i--) {
        // Check if the current character is not a space or a question mark
        if (s[i] != ' ' && s[i] != '?') {
            ch = s[i]; // Store the character
            break; // Exit the loop once the character is found
        }
    }
    
    // Convert the character to lowercase for uniform comparison
    ch = std::tolower(ch);
    
    // Check if the character is a vowel or 'y'
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        std::cout << "YES" << std::endl; // Print "YES" if it is a vowel
    } else {
        std::cout << "NO" << std::endl; // Print "NO" if it is not a vowel
    }
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
