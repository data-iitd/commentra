#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    // Read input string
    char s[1000001]; // Assuming the maximum length of the string is 1,000,000
    scanf("%s", s);

    // Check if all characters in the string are the same
    int len = strlen(s);
    int count[256] = {0}; // To count occurrences of each character

    for (int i = 0; i < len; i++) {
        count[(unsigned char)s[i]]++;
    }

    // Check if all characters are the same
    int unique_chars = 0;
    int min_count = INT_MAX;

    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            unique_chars++;
            min_count = min(min_count, count[i]);
        }
    }

    if (unique_chars == 1) {
        // If all characters are the same, print 0 and exit
        printf("0\n");
        return 0;
    }

    // Calculate the answer
    int ans = min_count * 2;

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
