#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if s1 is a valid substring of s2
bool isValid(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    bool map[256] = { false };

    // Populate the map with characters from s1
    for (int i = 0; i < len1; i++) {
        map[(unsigned char)s1[i]] = true;
    }

    // Check if all characters of s1 are present in s2
    for (int i = 0; i < len2; i++) {
        if (!map[(unsigned char)s2[i]]) return false;
    }

    return true;
}

int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);

    // Check if the strings are valid using the isValid method
    if (!isValid(s1, s2)) {
        printf("-1\n"); // Print -1 if strings are not valid
        return 0;
    }

    int m1[256] = { 0 }, m2[256] = { 0 };

    // Populate the array with the frequency of each character in s1
    for (int i = 0; i < strlen(s1); i++) {
        m1[(unsigned char)s1[i]]++;
    }

    // Populate the array with the frequency of each character in s2
    for (int i = 0; i < strlen(s2); i++) {
        m2[(unsigned char)s2[i]]++;
    }

    int ans = 0;
    bool hs[256] = { false };

    // Iterate over the characters of s2
    for (int i = 0; i < strlen(s2); i++) {
        if (!hs[(unsigned char)s2[i]]) {
            hs[(unsigned char)s2[i]] = true; // Mark character as processed
            int x1 = m1[(unsigned char)s2[i]]; // Get frequency of character in s1
            int x2 = m2[(unsigned char)s2[i]]; // Get frequency of character in s2
            x1 = x1 < x2 ? x1 : x2; // Calculate minimum frequency
            ans += x1; // Add minimum frequency to answer
        }
    }

    printf("%d\n", ans); // Print the final answer

    return 0;
}
