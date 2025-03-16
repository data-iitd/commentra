#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int isValid(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int map[256] = {0}; // Assuming ASCII characters

    // Mark characters present in s1
    for (int i = 0; i < len1; i++) {
        map[(unsigned char)s1[i]] = 1;
    }

    // Check if all characters in s2 are present in s1
    for (int i = 0; i < len2; i++) {
        if (map[(unsigned char)s2[i]] == 0) {
            return 0; // Not all characters are present
        }
    }
    return 1; // All characters are valid
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    int m1[256] = {0}, m2[256] = {0};
    int ans = 0;
    int hs[256] = {0};

    // Read two strings from the input
    scanf("%s %s", s1, s2);

    // Validate the input strings; if invalid, print -1 and exit
    if (!isValid(s1, s2)) {
        printf("-1\n");
        return 0;
    }

    // Count the frequency of each character in the first string
    for (int i = 0; s1[i] != '\0'; i++) {
        m1[(unsigned char)s1[i]]++;
    }

    // Count the frequency of each character in the second string
    for (int i = 0; s2[i] != '\0'; i++) {
        m2[(unsigned char)s2[i]]++;
    }

    // Calculate the minimum frequency of each character present in both strings
    for (int i = 0; s2[i] != '\0'; i++) {
        if (!hs[(unsigned char)s2[i]]) {
            hs[(unsigned char)s2[i]] = 1;
            int x1 = m1[(unsigned char)s2[i]];
            int x2 = m2[(unsigned char)s2[i]];
            x1 = x1 < x2 ? x1 : x2;
            ans += x1;
        }
    }

    // Print the final result
    printf("%d\n", ans);

    return 0;
}
