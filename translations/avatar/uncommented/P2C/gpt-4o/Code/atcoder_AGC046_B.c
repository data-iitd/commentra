#include <stdio.h>

#define MOD 998244353

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    
    long long d[C + 1][D + 1];
    
    // Initialize the array
    for (int i = 0; i <= C; i++) {
        for (int j = 0; j <= D; j++) {
            d[i][j] = 0;
        }
    }
    
    d[A][B] = 1;

    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            d[i][j] = (d[i][j] + (d[i][j - 1] * i) % MOD + (d[i - 1][j] * j) % MOD - (d[i - 1][j - 1] * (i - 1) % MOD * (j - 1) % MOD) % MOD + MOD) % MOD) % MOD;
        }
    }

    printf("%lld\n", d[C][D]);
    
    return 0;
}

// <END-OF-CODE>
