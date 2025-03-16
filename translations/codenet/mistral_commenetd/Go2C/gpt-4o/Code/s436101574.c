#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000000

// Function to read a single string
void scanString(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// Function to get the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to get the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Function to compare two strings for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Main function
int main() {
    char s[MAX_LEN + 1], t[MAX_LEN + 1];
    char *ans[MAX_LEN];
    int ans_count = 0;

    // Reading input strings s and t
    scanString(s, sizeof(s));
    scanString(t, sizeof(t));

    int len_s = strlen(s);
    int len_t = strlen(t);

    // Iterating through all possible substrings of s that have the same length as t
    for (int i = 0; i <= len_s - len_t; i++) {
        char ss[MAX_LEN + 1];
        strcpy(ss, s); // Copy s to ss

        bool f = true;
        for (int j = 0; j < len_t; j++) {
            // If the current character of s does not match the current character of t or is not '?'
            if (ss[i + j] != t[j] && ss[i + j] != '?') {
                f = false;
                break;
            } else {
                // Replacing the current character of s with the corresponding character of t
                ss[i + j] = t[j];
            }
        }
        // If the current substring matches the pattern t
        if (f) {
            // Replace '?' with 'a'
            for (int k = 0; k < len_s; k++) {
                if (ss[k] == '?') {
                    ss[k] = 'a';
                }
            }
            // Store the modified string in the answer array
            ans[ans_count] = strdup(ss);
            ans_count++;
        }
    }

    // Sorting the answer array in ascending order
    qsort(ans, ans_count, sizeof(char *), compare);

    // Checking if the answer array is empty
    if (ans_count == 0) {
        // Printing "UNRESTORABLE" if the answer array is empty
        printf("UNRESTORABLE\n");
    } else {
        // Printing the first element of the answer array
        printf("%s\n", ans[0]);
    }

    // Freeing allocated memory
    for (int i = 0; i < ans_count; i++) {
        free(ans[i]);
    }

    return 0;
}

// <END-OF-CODE>
