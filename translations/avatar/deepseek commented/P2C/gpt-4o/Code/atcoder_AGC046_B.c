#include <stdio.h>

#define MOD 998244353

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Initialize a 2D array d with dimensions (C+1) x (D+1), filled with zeros
    long long d[C + 1][D + 1];
    for (int i = 0; i <= C; i++) {
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
            d[i][j] = (d[i][j] + (d[i][j - 1] * i % MOD + d[i - 1][j] * j % MOD - d[i - 1][j - 1] * (i - 1) % MOD * (j - 1) % MOD + MOD) % MOD) % MOD) % MOD;
        }
    }

    // Print the value at the bottom-right corner of the array
    printf("%lld\n", d[C][D]);

    return 0;
}

// <END-OF-CODE>
