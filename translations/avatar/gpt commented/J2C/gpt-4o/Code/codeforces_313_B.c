#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char *s, int q) {
    int n = strlen(s);
    int *cum = (int *)malloc((n + 1) * sizeof(int));
    cum[0] = 0;
    cum[n] = 0;

    // Fill the cumulative array with counts of consecutive characters
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            cum[i] = cum[i - 1] + 1; // Increment count if the current character is the same as the previous
        else
            cum[i] = cum[i - 1]; // Carry forward the previous count if different
    }

    // Process each query
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        r--; // Adjust for 0-based index
        // Calculate and print the result for the current query
        printf("%d\n", cum[r] - cum[l - 1]);
    }

    free(cum);
}

int main() {
    char s[100001]; // Assuming the maximum length of the string is 100000
    int q;

    // Read the string
    scanf("%s", s);
    // Read the number of queries
    scanf("%d", &q);

    // Call the solve function to handle the input and produce output
    solve(s, q);

    return 0;
}

// <END-OF-CODE>
