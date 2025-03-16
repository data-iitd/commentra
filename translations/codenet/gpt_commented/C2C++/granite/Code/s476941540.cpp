
#include <iostream>
#include <cctype>

int main() {
    // Declare variables: 'i' for loop control, 'alpha' array to count occurrences of each letter, and 'ch' for character input
    int i, alpha[26];
    char ch;

    // Initialize the alpha array to zero for all 26 letters of the alphabet
    for(i = 0; i < 26; i++) {
        alpha[i] = 0;
    }

    // Infinite loop to read characters until EOF (End of File) is encountered
    while(1) {
        ch = std::cin.get(); // Read a character from standard input
        if(std::cin.eof()) break; // Exit the loop if EOF is reached

        // Check if the character is an alphabet letter
        if(std::isalpha(ch)) {
            // If the character is uppercase, increment the corresponding index in the alpha array
            if(std::isupper(ch)) {
                alpha[ch - 65]++; // 'A' is at index 0, 'B' at index 1,..., 'Z' at index 25
            } else {
                // If the character is lowercase, increment the corresponding index in the alpha array
                alpha[ch - 97]++; // 'a' is at index 0, 'b' at index 1,..., 'z' at index 25
            }
        }
    }

    // Print the count of each letter from 'a' to 'z'
    ch = 'a'; // Start with the letter 'a'
    for(i = 0; i < 26; i++, ch++) {
        std::cout << ch << " : " << alpha[i] << std::endl; // Output the letter and its count
    }

    return 0; // Return success
}

