#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100001];
    int cum[100001];
    int q, l, r;

    // Read the string
    scanf("%s", s);

    // Initialize the cumulative array
    int len = strlen(s);
    cum[0] = cum[len] = 0;

    // Fill the cumulative array with counts of consecutive characters
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1])
            cum[i] = cum[i - 1] + 1; // Increment count if the current character is the same as the previous
        else
            cum[i] = cum[i - 1]; // Carry forward the previous count if different
    }

    // Read the number of queries
    scanf("%d", &q);

    // Process each query
    while (q--) {
        // Read the range for the query
        scanf("%d %d", &l, &r);

        // Calculate and print the result for the current query
        printf("%d\n", cum[r - 1] - cum[l - 1]);
    }

    return 0;
}
