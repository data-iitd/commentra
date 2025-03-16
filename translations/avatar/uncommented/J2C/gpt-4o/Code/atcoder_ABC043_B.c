#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(const char *s) {
    char *d = (char *)malloc(strlen(s) + 1); // Allocate memory for the result
    int length = 0; // Length of the result string

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        switch (c) {
            case '0':
                d[length++] = '0'; // Append '0'
                break;
            case '1':
                d[length++] = '1'; // Append '1'
                break;
            case 'B':
                if (length > 0) {
                    length--; // Remove the last character
                }
                break;
        }
    }
    d[length] = '\0'; // Null-terminate the string
    printf("%s\n", d); // Print the result
    free(d); // Free allocated memory
}

int main() {
    char s[100000]; // Assuming the input string will not exceed 100000 characters
    scanf("%s", s); // Read the input string
    solve(s); // Call the solve function
    return 0;
}

// <END-OF-CODE>
