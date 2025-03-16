#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a character is a Latin letter
bool isLatinLetter(char c) {
    // Check if the character falls within the ASCII range of Latin letters
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
    // Check if the character is a dot, comma, exclamation mark, or question mark
    if (c == '.') return true;
    if (c == ',') return true;
    if (c == '!') return true;
    if (c == '?') return true;
    // If none of the above conditions are met, return false
    return false;
}

int main() {
    // Declare variables to read input from the console and write output to the console
    char c;
    bool firstChar = true;

    // Reading a character from the console
    while ((c = getchar()) != EOF) {
        // If the character is a Latin letter, append it to the output with a space before it if the previous character was not a Latin letter
        if (isLatinLetter(c)) {
            if (!firstChar && !isLatinLetter(getchar())) {
                putchar(' ');
            }
            putchar(c);
            firstChar = false;
        }
        // If the character is a punctuation mark, append it directly to the output without a space
        else if (isPunctuation(c)) {
            putchar(c);
        }
    }

    return 0;
}
