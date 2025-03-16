#include <stdio.h>

#define MOD 998244353

int main() {
    // Read input values A, B, C, D
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Initialize a 2D array (matrix) d with dimensions (C+1) x (D+1) filled with zeros
    long long d[C + 1][D + 1];
    for (int i = 0; i <= C; i++) {
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
            d[i][j] = (d[i][j] + (d[i][j - 1] * i) % MOD + (d[i - 1][j] * j) % MOD - (d[i - 1][j - 1] * (i - 1) % MOD * (j - 1) % MOD) % MOD + MOD) % MOD) % MOD;
        }
    }

    // Output the final result from the bottom-right corner of the matrix d
    printf("%lld\n", d[C][D]);

    return 0;
}

// <END-OF-CODE>
