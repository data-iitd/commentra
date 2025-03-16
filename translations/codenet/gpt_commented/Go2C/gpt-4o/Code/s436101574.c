#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000000

// Function to read a string from input
void scanString(char *buffer) {
    scanf("%s", buffer);
}

// Function to replace '?' with 'a' in a string
<<<<<<< HEAD
void replaceQuestionMark(char *str) {
=======
void replaceQuestionMarks(char *str) {
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; str[i]; i++) {
        if (str[i] == '?') {
            str[i] = 'a';
        }
    }
}

<<<<<<< HEAD
// Function to compare two strings for sorting
int compare(const void *a, const void *b) {
=======
// Function to compare two strings for qsort
int compareStrings(const void *a, const void *b) {
>>>>>>> 98c87cb78a (data updated)
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    char *ans[MAX_LEN];
    int ansCount = 0;

    // Read the first string (s)
    scanString(s);
    // Read the second string (t)
    scanString(t);

    int lenS = strlen(s);
    int lenT = strlen(t);

    // Iterate through the first string to find occurrences of the second string
    for (int i = 0; i <= lenS - lenT; i++) {
        bool valid = true; // Flag to check if the current position is valid
        char ss[MAX_LEN]; // Create a copy of the original string
        strcpy(ss, s); // Copy the original string into ss

        // Check if the substring of s can match t
        for (int j = 0; j < lenT; j++) {
            // If characters do not match and are not '?', set flag to false
            if (s[i + j] != t[j] && s[i + j] != '?') {
                valid = false;
                break;
            } else {
                // Replace '?' with the corresponding character from t
                ss[i + j] = t[j];
            }
        }
        // If the substring matched, replace remaining '?' with 'a' and store the result
        if (valid) {
<<<<<<< HEAD
            replaceQuestionMark(ss);
=======
            replaceQuestionMarks(ss);
>>>>>>> 98c87cb78a (data updated)
            ans[ansCount] = strdup(ss); // Store the result
            ansCount++;
        }
    }

    // Sort the possible answers
<<<<<<< HEAD
    qsort(ans, ansCount, sizeof(char *), compare);
=======
    qsort(ans, ansCount, sizeof(char *), compareStrings);
>>>>>>> 98c87cb78a (data updated)

    // Output the result: either the first valid answer or "UNRESTORABLE"
    if (ansCount == 0) {
        printf("UNRESTORABLE\n");
    } else {
        printf("%s\n", ans[0]);
    }

    // Free allocated memory
    for (int i = 0; i < ansCount; i++) {
        free(ans[i]);
    }

    return 0;
}

// <END-OF-CODE>
