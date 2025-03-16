#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Allocate memory for the 2D array d
    int **d = (int **)malloc((C + 1) * sizeof(int *));
    for (int i = 0; i <= C; i++) {
        d[i] = (int *)malloc((D + 1) * sizeof(int));
        for (int j = 0; j <= D; j++) {
            d[i][j] = 0;
        }
    }

    // Set the starting point in the matrix d at position (A, B) to 1
    d[A][B] = 1;

    // Iterate over the range from A to C (inclusive) for the first dimension
    for (int i = A; i <= C; i++) {
        // Iterate over the range from B to D (inclusive) for the second dimension
        for (int j = B; j <= D; j++) {
            // Update the current cell d[i][j] using the values from the previous cells
            d[i][j] = (d[i][j] + (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1))) % MOD;
        }
    }

    // Output the final result from the bottom-right corner of the matrix d
    printf("%d\n", d[C][D]);

    // Free the allocated memory
    for (int i = 0; i <= C; i++) {
        free(d[i]);
    }
    free(d);

    return 0;
}
