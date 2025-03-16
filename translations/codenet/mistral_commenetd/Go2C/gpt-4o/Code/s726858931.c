#include <stdio.h>  // Include standard I/O library
#include <string.h> // Include string library for string operations

// Function to read a string from standard input
void nextStr(char *s, int size) {
    fgets(s, size, stdin); // Read a line of input
    s[strcspn(s, "\n")] = 0; // Remove newline character if present
}

// Main function
int main() {
    // Allocate buffer for input string
    char s[1001]; // Buffer size of 1000 + 1 for null terminator
    nextStr(s, sizeof(s)); // Read the input string

    // Initialize variable c with 'a'
    char c = 'a';

    // Check all characters from 'a' to 'z' in the string s
    for (int j = 0; j < 26; j++) {
        // Initialize variable found as false
        int found = 0;

        // Iterate through each character in the string s
        for (int i = 0; i < strlen(s); i++) {
            // If current character matches c, set found to true and break the loop
            if (s[i] == c) {
                found = 1;
                break;
            }
        }

        // If character c is not found in the string s, print it and return
        if (!found) {
            printf("%c\n", c);
            return 0;
        }

        // Increment variable c
        c++;
    }

    // If no character from 'a' to 'z' is found in the string s, print "None"
    printf("None\n");
    return 0;
}

// <END-OF-CODE>
