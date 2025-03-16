

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

bool isValid(char *s1, char *s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    bool map[256] = {false};

    // Populate the map with characters from s1
    for (int i = 0; i < n1; i++) {
        map[s1[i]] = true;
    }

    // Check if all characters of s1 are present in s2
    for (int i = 0; i < n2; i++) {
        if (!map[s2[i]]) return false;
    }

    return true;
}

int main() {
    char s1[1000], s2[1000];
    scanf("%s %s", s1, s2);

    // Check if the strings are valid using the isValid method
    if (!isValid(s1, s2)) {
        printf("-1\n"); // Print -1 if strings are not valid
    } else {
        int m1[256] = {0}, m2[256] = {0};
        int ans = 0;
        bool processed[256] = {false};

        // Populate the m1 and m2 arrays with the frequency of each character in s1 and s2
        for (int i = 0; s1[i]!= '\0'; i++) {
            m1[s1[i]]++;
        }
        for (int i = 0; s2[i]!= '\0'; i++) {
            m2[s2[i]]++;
        }

        // Iterate over the characters of s2
        for (int i = 0; s2[i]!= '\0'; i++) {
            if (!processed[s2[i]]) {
                processed[s2[i]] = true; // Mark character as processed
                int x1 = m1[s2[i]]; // Get frequency of character in s1
                int x2 = m2[s2[i]]; // Get frequency of character in s2
                x1 = (x1 < x2)? x1 : x2; // Calculate minimum frequency
                ans += x1; // Add minimum frequency to answer
            }
        }

        printf("%d\n", ans); // Print the final answer
    }

    return 0;
}

// END-OF-CODE