#include <iostream>
#include <cstring>

// Array to hold the count of each letter (a-z)
int c[26] = {0};

int main() {
    // Declare a string to hold the input
    std::string str;

    // Read strings from standard input until EOF
    while (std::cin >> str) {
        // Iterate through each character in the string
        for (char p : str) {
            // Check if the character is a lowercase letter
            if ('a' <= p && p <= 'z') {
                // Increment the count for the corresponding letter
                c[p - 'a']++;
            } 
            // Check if the character is an uppercase letter
            else if ('A' <= p && p <= 'Z') {
                // Increment the count for the corresponding letter (converted to lowercase)
                c[p - 'A']++;
            }
        }
    }

    // Print the count of each letter from 'a' to 'z'
    for (int i = 0; i < 26; i++) {
        std::cout << static_cast<char>('a' + i) << " : " << c[i] << std::endl; 
    }

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
