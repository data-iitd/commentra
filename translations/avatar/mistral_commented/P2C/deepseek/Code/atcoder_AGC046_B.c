#include <stdio.h>
#include <stdlib.h>

#define m 1000000007

int main() {
    int A, B, C, D;
    // Read integers A, B, C, D from input
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Allocate memory for a 2D array 'd' with dimensions (C+1) x (D+1)
    int **d = (int **)malloc((C + 1) * sizeof(int *));
    for (int i = 0; i <= C; i++) {
        d[i] = (int *)malloc((D + 1) * sizeof(int));
        for (int j = 0; j <= D; j++) {
            d[i][j] = 0;
        }
    }

    // Set the value of d[A][B] to 1
    d[A][B] = 1;

    // Matrix multiplication using dynamic programming approach
    // Iterate through the rows from A to C
    for (int i = A; i <= C; i++) {
        // Iterate through the columns from B to D
        for (int j = B; j <= D; j++) {
            // Calculate the value of d[i][j] using the previous values
            d[i][j] = (d[i][j] + (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1))) % m;
        }
    }

    // Print the final value of d[C][D]
    printf("%d\n", d[C][D]);

    // Free allocated memory
    for (int i = 0; i <= C; i++) {
        free(d[i]);
    }
    free(d);

    return 0;
}
