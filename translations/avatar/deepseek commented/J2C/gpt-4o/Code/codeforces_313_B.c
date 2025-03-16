#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char *s, int q) {
    int n = strlen(s);
    int *cum = (int *)malloc((n + 1) * sizeof(int));
    cum[0] = 0;
    
    // Fill the cumulative array with counts of consecutive identical characters
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cum[i] = cum[i - 1] + 1;
        } else {
            cum[i] = cum[i - 1];
        }
    }
    cum[n] = cum[n - 1]; // Last element is the same as the second last

    // Process each query
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        r--; // Convert to 0-based index
        printf("%d\n", cum[r] - cum[l - 1]);
    }

    free(cum);
}

int main() {
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s); // Read the input string

    int q;
    scanf("%d", &q); // Read the number of queries

    solve(s, q); // Call the solve function

    return 0;
}

// <END-OF-CODE>
