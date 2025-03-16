#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // Read the dimensions of the grid (n: number of rows, m: number of columns)

    int *c = (int *)malloc(n * sizeof(int)); // Allocate memory for differences
    int count = 0; // To count unique non-negative differences
    int foundNegative = 0; // Flag for negative differences

    for (int i = 0; i < n; i++) {
        char s[m + 1]; // +1 for null terminator
        scanf("%s", s); // Read the string for the current row

        int indexS = -1, indexG = -1; // Initialize indices for 'S' and 'G'
        for (int j = 0; j < m; j++) {
            if (s[j] == 'S') indexS = j; // Find index of 'S'
            if (s[j] == 'G') indexG = j; // Find index of 'G'
        }

        if (indexS != -1 && indexG != -1) {
            int diff = indexS - indexG; // Calculate the difference
            if (diff < 0) {
                foundNegative = 1; // Set flag if difference is negative
            } else {
                // Check if the difference is already counted
                int isUnique = 1;
                for (int k = 0; k < count; k++) {
                    if (c[k] == diff) {
                        isUnique = 0; // Not unique
                        break;
                    }
                }
                if (isUnique) {
                    c[count++] = diff; // Store unique non-negative difference
                }
            }
        }
    }

    if (foundNegative) {
        printf("-1\n"); // Print '-1' if any negative difference found
    } else {
        printf("%d\n", count); // Print the number of unique non-negative differences
    }

    free(c); // Free allocated memory
    return 0;
}
