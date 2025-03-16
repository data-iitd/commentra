#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_NUM 26

int main() {
    char str[1024];
    int memo[ALPHABET_NUM] = {0};

    // Read input until EOF.
    while (fgets(str, sizeof(str), stdin) != NULL) {
        for (int i = 0; i < strlen(str); i++) {
            char c = str[i];

            if ('a' <= c && c <= 'z') {
                // Increment count for lowercase letters.
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                // Increment count for uppercase letters.
                memo[c - 'A']++;
            }
        }
    }

    // Print the count of each letter.
    for (int i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", 'a' + i, memo[i]);
    }

    return 0;
}

