#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

// Function to process the input string and generate the output
void solve(const char *s) {
    char d[MAX_LENGTH];
    int length = 0;

    // Process each character in the input string
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        switch (c) {
            case '0':
                // Append '0' to the output
                d[length++] = '0';
                break;
            case '1':
                // Append '1' to the output
                d[length++] = '1';
                break;
            case 'B':
                // Handle the 'B' character by removing the last character if possible
                if (length > 0) {
                    length--; // Remove the last character
                }
                break;
        }
    }
    // Null-terminate the output string
    d[length] = '\0';
    // Output the final result
    printf("%s\n", d);
}

int main() {
    // Buffer to hold the input string
    char s[MAX_LENGTH];

    // Read the input string
    if (fgets(s, sizeof(s), stdin) != NULL) {
        // Remove the newline character if present
        s[strcspn(s, "\n")] = '\0';
        // Solve the problem
        solve(s);
    }

    return 0;
}

// <END-OF-CODE>
