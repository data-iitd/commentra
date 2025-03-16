#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100001];
    int cum[100001];
    int q, l, r;

    // Read the input string
    scanf("%s", s);

    // Initialize the cumulative array to store counts of consecutive identical characters
    int len = strlen(s);
    cum[0] = 0;
    cum[len] = 0;

    // Fill the cumulative array with counts of consecutive identical characters
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1])
            cum[i] = cum[i - 1] + 1;
        else
            cum[i] = cum[i - 1];
    }

    // Read the number of queries
    scanf("%d", &q);

    // Process each query
    while (q--) {
        scanf("%d %d", &l, &r);

        // Calculate and print the result for the query
        printf("%d\n", cum[r - 1] - cum[l - 1]);
    }

    return 0;
}
