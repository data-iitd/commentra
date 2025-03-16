
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Ensure the output is flushed before exiting
    setvbuf(stdout, NULL, _IONBF, 0);

    // Read the first string of runes (s)
    char s[100001];
    fgets(s, 100001, stdin);
    // Read the second string of runes (t)
    char t[100001];
    fgets(t, 100001, stdin);

    // Initialize a slice to hold possible answers
    char **ans = (char **)malloc(sizeof(char *) * 100001);
    int ans_len = 0;

    // Iterate through the first string to find occurrences of the second string
    for (int i = 0; i < strlen(s) - strlen(t) + 1; i++) {
        int f = 1; // Flag to check if the current position is valid
        char ss[100001]; // Create a copy of the original string
        strcpy(ss, s); // Copy the original string into ss

        // Check if the substring of s can match t
        for (int j = 0; j < strlen(t); j++) {
            // If characters do not match and are not '?', set flag to false
            if (s[i + j]!= t[j] && s[i + j]!= '?') {
                f = 0;
                break;
            } else {
                // Replace '?' with the corresponding character from t
                ss[i + j] = t[j];
            }
        }
        // If the substring matched, replace remaining '?' with 'a' and store the result
        if (f) {
            char *tmp = (char *)malloc(sizeof(char) * 100001);
            strcpy(tmp, ss);
            ans[ans_len++] = tmp;
        }
    }

    // Sort the possible answers
    qsort(ans, ans_len, sizeof(char *), cmpstr);

    // Output the result: either the first valid answer or "UNRESTORABLE"
    if (ans_len == 0) {
        printf("UNRESTORABLE\n");
    } else {
        printf("%s\n", ans[0]);
    }

    // Free memory for possible answers
    for (int i = 0; i < ans_len; i++) {
        free(ans[i]);
    }
    free(ans);

    return 0;
}

// Function to compare two strings for sorting
int cmpstr(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// End of code
