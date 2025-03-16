#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007
#define INF INT_MAX

int main() {
    // Read input string
    char s[1000001]; // Assuming the maximum length of the string is 1,000,000
    scanf("%s", s);

    // Check if all characters in the string are the same
    int len = strlen(s);
    int all_same = 1;
    for (int i = 1; i < len; i++) {
        if (s[i] != s[0]) {
            all_same = 0;
            break;
        }
    }
    if (all_same) {
        printf("0\n"); // If true, print 0 and exit
        return 0;
    }

    // Count the occurrences of each character
    int count[256] = {0}; // Assuming ASCII characters
    for (int i = 0; i < len; i++) {
        count[(unsigned char)s[i]]++;
    }

    // Find the minimum frequency of any character
    int min_freq = INF;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0 && count[i] < min_freq) {
            min_freq = count[i];
        }
    }

    // Calculate the answer as twice the minimum frequency of any character
    int ans = min_freq * 2;

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
