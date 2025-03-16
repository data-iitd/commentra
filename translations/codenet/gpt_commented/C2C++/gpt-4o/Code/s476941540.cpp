#include <iostream>
#include <cctype>

int main() {
    // Declare variables: 'i' for loop control, 'alpha' array to count occurrences of each letter
    int i, alpha[26] = {0}; // Initialize the alpha array to zero for all 26 letters of the alphabet

    char ch;

    // Infinite loop to read characters until EOF (End of File) is encountered
    while (true) {
        ch = std::cin.get(); // Read a character from standard input
        if (ch == EOF) break; // Exit the loop if EOF is reached

        // Check if the character is an alphabet letter
        if (std::isalpha(ch)) {
            // If the character is uppercase, increment the corresponding index in the alpha array
            if (std::isupper(ch)) {
                alpha[ch - 'A']++; // 'A' is at index 0, 'B' at index 1, ..., 'Z' at index 25
            } else {
                // If the character is lowercase, increment the corresponding index in the alpha array
                alpha[ch - 'a']++; // 'a' is at index 0, 'b' at index 1, ..., 'z' at index 25
            }
        }
    }

    // Print the count of each letter from 'a' to 'z'
    ch = 'a'; // Start with the letter 'a'
    for (i = 0; i < 26; i++, ch++) {
        std::cout << ch << " : " << alpha[i] << std::endl; // Output the letter and its count
    }

    return 0; // Return success
}

// <END-OF-CODE>
