#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Define a maximum length for the string

// Function to solve the problem
void solve(const char *s) {
    char d[MAX_LENGTH]; // Output string
    int length = 0; // Current length of the output string

    for (int i = 0; s[i] != '\0'; i++) { // Iterate through each character in the input string
        char c = s[i];
        switch (c) { // Switch statement to handle different characters
            case '0':
                d[length++] = '0'; // Append "0" to the output string
                break;
            case '1':
                d[length++] = '1'; // Append "1" to the output string
                break;
            case 'B':
                if (length > 0) { // If there is a character in the output string
                    length--; // Remove the last character from the output string
                }
                break;
        }
    }

    d[length] = '\0'; // Null-terminate the output string
    printf("%s\n", d); // Print the output string to the console
}

// Main function
int main() {
    char input[MAX_LENGTH]; // Input string

    // Read the input string from the console
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        solve(input); // Call the solve function with the input string
    }

    return 0; // Return success
}

// <END-OF-CODE>
