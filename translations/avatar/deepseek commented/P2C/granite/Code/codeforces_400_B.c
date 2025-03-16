

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Read the dimensions of the grid (n: number of rows, m: number of columns)

    int c[n];
    for (int i = 0; i < n; i++) {
        char s[m + 1];
        scanf("%s", s);
        // Read the string for each row

        c[i] = -1;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'S') {
                c[i] = j;
                break;
            }
        }
        // Find the index of 'S' in each row and store it in the array 'c'.
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (c[i]!= -1) {
            int diff = 0;
            for (int j = 0; j < n; j++) {
                if (c[j]!= -1 && i!= j) {
                    diff = abs(c[i] - c[j]);
                    break;
                }
            }
            // Calculate the difference between the indices of 'S' and 'G' for each row.
            // Store these differences in the array 'c'.

            if (diff == 0) {
                count++;
            }
            // Check if there is any negative difference in the array 'c'.
            // If there is, print '-1'. Otherwise, print the number of unique non-negative differences.
        }
    }

    printf("%d\n", count);
    // Print the number of unique non-negative differences.

    return 0;
}
