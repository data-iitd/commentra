#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_NUM 26

int memo[ALPHABET_NUM];

int main() {
    char str[1000]; // Assuming a maximum length for the input string

    while (fgets(str, sizeof(str), stdin)) {
        // Remove newline character if present
        str[strcspn(str, "\n")] = 0;

        if (strlen(str) == 0) {
            break;
        }

        for (int i = 0; i < strlen(str); i++) {
            char c = str[i];

            if ('a' <= c && c <= 'z') {
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                memo[c - 'A']++;
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", (char)(i + 'a'), memo[i]);
    }

    return 0;
}

// <END-OF-CODE>
