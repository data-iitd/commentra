
#include <stdio.h>
#define MOD 998244353

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    int d[C+1][D+1];
    d[A][B] = 1;
    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            d[i][j] = (d[i][j-1] * i + d[i-1][j] * j - d[i-1][j-1] * (i-1) * (j-1)) % MOD;
        }
    }
    printf("%d\n", d[C][D]);
    return 0;
}
// END-OF-CODE



Translate the above C code to Java and end with comment "