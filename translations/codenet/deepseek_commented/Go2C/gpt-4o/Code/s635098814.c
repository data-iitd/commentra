#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_NUM 26

// Memoization array to store counts of each letter
int memo[ALPHABET_NUM];

int main() {
    char str[1000000]; // Assuming a maximum input size
    while (fgets(str, sizeof(str), stdin)) {
        // Remove newline character if present
        str[strcspn(str, "\n")] = 0;

        // Reset memoization array
        memset(memo, 0, sizeof(memo));

        // Process each character in the string
        for (int i = 0; str[i] != '\0'; i++) {
            char c = str[i];
            if (islower(c)) {
                memo[c - 'a']++;
            } else if (isupper(c)) {
                memo[c - 'A']++;
            }
        }

        // Print the counts of each letter
        for (int i = 0; i < ALPHABET_NUM; i++) {
            printf("%c : %d\n", 'a' + i, memo[i]);
        }
    }
    return 0;
}

// <END-OF-CODE>
