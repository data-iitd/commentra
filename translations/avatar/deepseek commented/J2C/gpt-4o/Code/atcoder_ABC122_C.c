#include <stdio.h>

#define MOD 1000000007

int main() {
    // Read the length of the string and the number of queries
    int n, q;
    scanf("%d %d", &n, &q);

    // Read the string
    char c[n + 1]; // +1 for null terminator
    scanf("%s", c);

    // Read the ranges for the queries
    int range[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &range[i][0], &range[i][1]);
    }

    // Initialize arrays to count "AC" fragments and store cumulative sums
    int frag[n + 1]; 
    int rui[n + 1];
    for (int i = 0; i <= n; i++) {
        frag[i] = 0;
        rui[i] = 0;
    }

    // Process the string to find "AC" fragments
    for (int i = 2; i <= n; i++) {
        if (c[i - 2] == 'A' && c[i - 1] == 'C') {
            // Increment the count of "AC" fragments at position i
            frag[i]++;
        }
        // Update the cumulative sum array
        rui[i] = rui[i - 1] + frag[i];
    }

    // Process the queries
    for (int i = 0; i < q; i++) {
        int left = range[i][0];
        int right = range[i][1];
        // Calculate the number of "AC" fragments in the given range
        printf("%d\n", rui[right] - rui[left]);
    }

    return 0;
}

// <END-OF-CODE>
