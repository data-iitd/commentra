#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    char s[1000]; // Assuming the input string will not exceed 999 characters
    fgets(s, sizeof(s), stdin); // Read a line of input
    int n = strlen(s);
    char sb[1000]; // StringBuilder equivalent
    int sbIndex = 0;

    if (n > 0) {
        sb[sbIndex++] = s[0]; // Append the first character
    }

    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                sb[sbIndex++] = ' '; // Add a space if the previous character is not a Latin letter
            }
            sb[sbIndex++] = c; // Append the Latin letter
        } else if (isPunctuation(c)) {
            sb[sbIndex++] = c; // Append the punctuation
        }
    }

    sb[sbIndex] = '\0'; // Null-terminate the string
    printf("%s\n", sb); // Print the result
    return 0;
}

// <END-OF-CODE>
