#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Initialize a 2D array d with dimensions (C+1) x (D+1), filled with zeros
    int **d = (int **)malloc((C + 1) * sizeof(int *));
    for (int i = 0; i <= C; i++) {
        d[i] = (int *)malloc((D + 1) * sizeof(int));
        for (int j = 0; j <= D; j++) {
            d[i][j] = 0;
        }
    }

    // Set the starting point for our calculations
    d[A][B] = 1;

    // Iterate over the range from A to C for the rows and from B to D for the columns
    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            // Update the value of d[i][j] based on its neighboring cells and some arithmetic operations
            if (i > A || j > B) {
                d[i][j] = (d[i][j] + (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1))) % MOD;
            }
        }
    }

    // Print the value at the bottom-right corner of the array
    printf("%d\n", d[C][D]);

    // Free the allocated memory
    for (int i = 0; i <= C; i++) {
        free(d[i]);
    }
    free(d);

    return 0;
}
