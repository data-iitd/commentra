
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store a character and its frequency
struct char_freq {
    char c;
    int freq;
};

// Function to check if s1 is a valid substring of s2
bool is_valid(char *s1, char *s2) {
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
    char s1[100000], s2[100000];
    scanf("%s %s", s1, s2);

    // Check if the strings are valid using the isValid method
    if (!is_valid(s1, s2)) {
        printf("-1\n");
    } else {
        int n1 = strlen(s1);
        int n2 = strlen(s2);
        struct char_freq m1[256] = {0};
        struct char_freq m2[256] = {0};

        // Populate the HashMap with the frequency of each character in s1
        for (int i = 0; i < n1; i++) {
            m1[s1[i]].freq++;
        }

        // Populate the HashMap with the frequency of each character in s2
        for (int i = 0; i < n2; i++) {
            m2[s2[i]].freq++;
        }

        int ans = 0;
        bool hs[256] = {false};

        // Iterate over the characters of s2
        for (int i = 0; i < n2; i++) {
            if (!hs[s2[i]]) {
                hs[s2[i]] = true;
                int x1 = m1[s2[i]].freq;
                int x2 = m2[s2[i]].freq;
                x1 = x1 < x2 ? x1 : x2;
                ans += x1;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

