
#include <stdio.h>
#include <string.h>

// Define a constant for modulo operations
#define mod 1000000007

int main() {
    // Read the length of the string and the number of queries
    int n, q;
    scanf("%d %d", &n, &q);

    // Read the string as a character array
    char c[n];
    scanf("%s", c);

    // Read the ranges for the queries and store them in a 2D array
    int range[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &range[i][0], &range[i][1]);
    }

    // Initialize arrays to count "AC" fragments and store cumulative sums
    int frag[n + 1];
    int rui[n + 1];
    memset(frag, 0, sizeof(frag));
    memset(rui, 0, sizeof(rui));

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
