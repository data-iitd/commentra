#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256 // Maximum number of different characters

int main() {
    char s[100]; // Array to store the input string
    int freq[MAX_CHAR] = {0}; // Array to store the frequency of each character
    int uniqueChars = 0; // Counter for unique characters

    // Reading a string input from user
    scanf("%s", s);

    // Calculating frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        char currentChar = s[i];
        if (freq[currentChar] == 0) {
            uniqueChars++; // Increment unique character count
        }
        freq[currentChar]++; // Increment frequency of the current character
    }

    // Check if all characters have frequency 2
    int ok = 1; // Flag to check if all characters have frequency 2
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] != 0 && freq[i] != 2) {
            ok = 0; // Set flag to false if any character has frequency other than 2
            break;
        }
    }

    // Check if conditions are met
    if (ok && uniqueChars == 2) {
        printf("Yes\n"); // Print "Yes" if both conditions are true
    } else {
        printf("No\n"); // Print "No" if any character has frequency other than 2 or the size of unique characters is not 2
    }

    return 0; // Return success
}

// <END-OF-CODE>
