#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000000

// Function to read a string from input
<<<<<<< HEAD
void scanString(char *buffer, int size) {
    fgets(buffer, size, stdin);
=======
void scanString(char *buffer) {
    fgets(buffer, MAX_LEN, stdin);
>>>>>>> 98c87cb78a (data updated)
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// Function to replace '?' with 'a' in a string
void replaceQuestionMark(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '?') {
            str[i] = 'a';
        }
    }
}

// Function to compare two strings for sorting
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char s[MAX_LEN], t[MAX_LEN];
<<<<<<< HEAD
    scanString(s, MAX_LEN);
    scanString(t, MAX_LEN);
=======
    scanString(s); // Read the first string
    scanString(t); // Read the second string
>>>>>>> 98c87cb78a (data updated)

    char *ans[MAX_LEN]; // Array to store possible valid strings
    int ansCount = 0; // Count of valid strings

    int lenS = strlen(s);
    int lenT = strlen(t);

    for (int i = 0; i <= lenS - lenT; i++) {
        bool valid = true; // Flag to check if the current position is valid
        char ss[MAX_LEN]; // Temporary string to hold the modified string
        strcpy(ss, s); // Copy the original string to the temporary string

        for (int j = 0; j < lenT; j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') { // Check for mismatch
                valid = false;
                break;
            } else {
                ss[i + j] = t[j]; // Replace character in the temporary string
            }
        }
        if (valid) {
            replaceQuestionMark(ss); // Replace '?' with 'a'
            ans[ansCount] = strdup(ss); // Store the valid string
            ansCount++;
        }
    }

    if (ansCount == 0) {
        printf("UNRESTORABLE\n"); // Print "UNRESTORABLE" if no valid string is found
    } else {
        qsort(ans, ansCount, sizeof(char *), compareStrings); // Sort the answer array
        printf("%s\n", ans[0]); // Print the smallest valid string
    }

    // Free allocated memory
    for (int i = 0; i < ansCount; i++) {
        free(ans[i]);
    }

    return 0;
}
