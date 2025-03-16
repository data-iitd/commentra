#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_NUM 26

// Declare a memoization array for counting letter occurrences.
int memo[ALPHABET_NUM];

int main() {
    char str[1000]; // Buffer to hold input strings

    // Read input until EOF
    while (fgets(str, sizeof(str), stdin)) {
        // Count occurrences of each letter
        for (int i = 0; str[i] != '\0'; i++) {
            char c = str[i];

            if (c >= 'a' && c <= 'z') {
                // Increment count for lowercase letters
                memo[c - 'a']++;
            } else if (c >= 'A' && c <= 'Z') {
                // Increment count for uppercase letters
                memo[c - 'A']++;
            } else {
                // Ignore non-alphabet characters
                continue;
            }
        }
    }

    // Print the count of each letter
    for (int i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", (char)(i + 'a'), memo[i]);
    }

    return 0;
}

// <END-OF-CODE>
