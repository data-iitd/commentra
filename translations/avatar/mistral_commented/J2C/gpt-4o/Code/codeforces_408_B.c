#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 256

bool isValid(const char *s1, const char *s2) {
    bool map[MAX_CHAR] = {false}; // Create a boolean array to store the presence of characters in the first string

    for (int i = 0; s1[i] != '\0'; i++) { // Iterate through each character in the first string
        map[(unsigned char)s1[i]] = true; // Mark the character as present in the array
    }

    for (int i = 0; s2[i] != '\0'; i++) { // Iterate through each character in the second string
        if (!map[(unsigned char)s2[i]]) { // If the character is not present in the first string, return false
            return false;
        }
    }

    return true; // If all characters in the second string are present in the first string, return true
}

int main() {
    char s1[100], s2[100]; // Declare arrays to hold the input strings

    scanf("%s %s", s1, s2); // Read the first and second strings from the input

    if (!isValid(s1, s2)) { // Check if the given strings are valid
        printf("-1\n"); // If not valid, print -1 and exit
        return 0;
    } else { // If the strings are valid, proceed with the computation
        int m1[MAX_CHAR] = {0}; // Array to store the frequency of characters in the first string
        int m2[MAX_CHAR] = {0}; // Array to store the frequency of characters in the second string

        for (int i = 0; s1[i] != '\0'; i++) { // Iterate through each character in the first string
            m1[(unsigned char)s1[i]]++; // Increment the count of the character
        }

        for (int i = 0; s2[i] != '\0'; i++) { // Iterate through each character in the second string
            m2[(unsigned char)s2[i]]++; // Increment the count of the character
        }

        int ans = 0; // Initialize the answer variable to 0
        bool hs[MAX_CHAR] = {false}; // Create a boolean array to store unique characters in the second string

        for (int i = 0; s2[i] != '\0'; i++) { // Iterate through each character in the second string
            if (!hs[(unsigned char)s2[i]]) { // If the character is not already in the array, add it and compute the answer
                hs[(unsigned char)s2[i]] = true; // Mark the character as seen
                int x1 = m1[(unsigned char)s2[i]]; // Get the count of the character in the first string
                int x2 = m2[(unsigned char)s2[i]]; // Get the count of the character in the second string
                x1 = (x1 < x2) ? x1 : x2; // Take the minimum count
                ans += x1; // Add the minimum count to the answer
            }
        }

        printf("%d\n", ans); // Print the answer
    }

    return 0;
}
