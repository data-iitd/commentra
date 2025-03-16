#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Function to check if the characters in s2 are all present in s1
int isValid(const char *s1, const char *s2) {
    int map[MAX_CHAR] = {0}; // Array to store characters from the first string

    // Add all characters from the first string to the map
    for (int i = 0; s1[i] != '\0'; i++) {
        map[(unsigned char)s1[i]] = 1; // Mark character as present
    }

    // Check if all characters in the second string are present in the first string
    for (int i = 0; s2[i] != '\0'; i++) {
        if (map[(unsigned char)s2[i]] == 0) {
            return 0; // Character not found
        }
    }
    return 1; // All characters are valid
}

int main() {
    // Create buffers to hold the input strings
    char s1[100], s2[100];

    // Read two strings from the input
    scanf("%s %s", s1, s2);

    // Validate the input strings; if invalid, print -1 and exit
    if (!isValid(s1, s2)) {
        printf("-1\n");
        return 0;
    } else {
        // Arrays to count the frequency of characters in both strings
        int m1[MAX_CHAR] = {0};
        int m2[MAX_CHAR] = {0};

        // Count the frequency of each character in the first string
        for (int i = 0; s1[i] != '\0'; i++) {
            m1[(unsigned char)s1[i]]++;
        }

        // Count the frequency of each character in the second string
        for (int i = 0; s2[i] != '\0'; i++) {
            m2[(unsigned char)s2[i]]++;
        }

        // Initialize a variable to hold the result
        int ans = 0;

        // Calculate the minimum frequency of each character present in both strings
        for (int i = 0; s2[i] != '\0'; i++) {
            if (m2[(unsigned char)s2[i]] > 0) {
                int x1 = m1[(unsigned char)s2[i]]; // Frequency in the first string
                int x2 = m2[(unsigned char)s2[i]]; // Frequency in the second string
                ans += (x1 < x2) ? x1 : x2; // Take the minimum frequency
                m2[(unsigned char)s2[i]] = 0; // Mark as counted
            }
        }

        // Print the final result
        printf("%d\n", ans);
    }

    return 0;
}

// <END-OF-CODE>
