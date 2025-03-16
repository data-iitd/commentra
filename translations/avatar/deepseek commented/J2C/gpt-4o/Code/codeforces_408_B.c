#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 256

// Function to check if s1 is a valid substring of s2
bool isValid(const char *s1, const char *s2) {
    bool map[MAX_CHAR] = {false}; // Array to track characters in s1

    // Populate the map with characters from s1
    for (int i = 0; s1[i] != '\0'; i++) {
        map[(unsigned char)s1[i]] = true;
    }

    // Check if all characters of s1 are present in s2
    for (int i = 0; s2[i] != '\0'; i++) {
        if (!map[(unsigned char)s2[i]]) {
            return false;
        }
    }

    return true;
}

int main() {
    char s1[100], s2[100]; // Assuming maximum length of strings is 99

    // Read first string
    scanf("%s", s1);
    // Read second string
    scanf("%s", s2);

    // Check if the strings are valid using the isValid method
    if (!isValid(s1, s2)) {
        printf("-1\n"); // Print -1 if strings are not valid
    } else {
        int m1[MAX_CHAR] = {0}; // Frequency array for s1
        int m2[MAX_CHAR] = {0}; // Frequency array for s2

        // Populate the frequency array for s1
        for (int i = 0; s1[i] != '\0'; i++) {
            m1[(unsigned char)s1[i]]++;
        }

        // Populate the frequency array for s2
        for (int i = 0; s2[i] != '\0'; i++) {
            m2[(unsigned char)s2[i]]++;
        }

        int ans = 0; // Initialize answer variable
        bool hs[MAX_CHAR] = {false}; // Array to track processed characters

        // Iterate over the characters of s2
        for (int i = 0; s2[i] != '\0'; i++) {
            unsigned char c = (unsigned char)s2[i];
            if (!hs[c]) {
                hs[c] = true; // Mark character as processed
                int x1 = m1[c]; // Get frequency of character in s1
                int x2 = m2[c]; // Get frequency of character in s2
                x1 = (x1 < x2) ? x1 : x2; // Calculate minimum frequency
                ans += x1; // Add minimum frequency to answer
            }
        }

        printf("%d\n", ans); // Print the final answer
    }

    return 0;
}

// <END-OF-CODE>
