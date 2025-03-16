
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s1, char *s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    // Create a HashMap to store characters from the first string
    bool map[256] = {false};

    // Add all characters from the first string to the map
    for (int i = 0; i < n1; i++) {
        map[s1[i]] = true;
    }

    // Check if all characters in the second string are present in the first string
    for (int i = 0; i < n2; i++) {
        if (!map[s2[i]]) return false;
    }
    return true; // All characters are valid
}

int main() {
    // Create a Scanner object to read input from the console
    char s1[1000], s2[1000];
    scanf("%s %s", s1, s2);

    // Validate the input strings; if invalid, print -1 and exit
    if (isValid(s1, s2) == false) {
        printf("-1\n");
    } else {
        // Create HashMaps to count the frequency of characters in both strings
        int m1[256] = {0}, m2[256] = {0};

        // Count the frequency of each character in the first string
        for (int i = 0; i < strlen(s1); i++) {
            m1[s1[i]]++;
        }

        // Count the frequency of each character in the second string
        for (int i = 0; i < strlen(s2); i++) {
            m2[s2[i]]++;
        }

        // Initialize a variable to hold the result
        int ans = 0;
        // Create a HashSet to track unique characters from the second string
        bool hs[256] = {false};

        // Calculate the minimum frequency of each character present in both strings
        for (int i = 0; i < strlen(s2); i++) {
            if (!hs[s2[i]]) {
                hs[s2[i]] = true;
                int x1 = m1[s2[i]]; // Frequency in the first string
                int x2 = m2[s2[i]]; // Frequency in the second string
                x1 = (x1 < x2)? x1 : x2; // Take the minimum frequency
                ans += x1; // Add to the result
            }
        }

        // Print the final result
        printf("%d\n", ans);
    }
    return 0;
}
