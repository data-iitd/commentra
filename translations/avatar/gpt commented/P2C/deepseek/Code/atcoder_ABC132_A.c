#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 1000

int main() {
    char S[MAX_CHARS];
    int c[256] = {0}; // Array to count occurrences of characters
    int unique_chars = 0;

    // Take input string from the user
    fgets(S, MAX_CHARS, stdin);

    // Count the frequency of each character in the string
    for (int i = 0; i < strlen(S); i++) {
        c[(unsigned char)S[i]]++;
    }

    // Create a set of unique characters from the input string
    int set[256] = {0};
    for (int i = 0; i < strlen(S); i++) {
        if (set[(unsigned char)S[i]] == 0) {
            set[(unsigned char)S[i]] = 1;
            unique_chars++;
        }
    }

    // Check if the number of unique characters is not equal to 2
    if (unique_chars != 2) {
        // If there are not exactly 2 unique characters, print "No" and exit
        printf("No\n");
        return 0;
    }

    // Check if each unique character appears exactly twice
    for (int i = 0; i < 256; i++) {
        if (set[i] && c[i] != 2) {
            // If any character does not appear exactly twice, print "No" and exit
            printf("No\n");
            return 0;
        }
    }

    // If both conditions are satisfied, print "Yes"
    printf("Yes\n");
    return 0;
}
