#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
const int mod = 1e9 + 7;
const int NMAX = 1000010;

ll fac[NMAX], finv[NMAX], inv[NMAX];

// Initialize factorial, inverse factorial, and inverse arrays
void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < NMAX; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// Calculate the binomial coefficient C(n, k)
ll C(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

// Main function logic
int main() {
    init();
    int X, Y;
    scanf("%d %d", &X, &Y);
    // Check if the sum of X and Y is divisible by 3
    if ((X + Y) % 3 != 0) {
        printf("0\n");
        return 0;
    }
    // Calculate the number of steps needed to reach the target point
    int n = (X + Y) / 3 + 1;
    // Calculate the number of steps needed to reach the target point from the most upper point
    int k = 2 * (n - 1) - Y + 1; // y = 2xより最も上にくる点からどれだけ離れているか。
    // Output the number of ways to reach the target point
    printf("%lld\n", C(n - 1, k - 1));
    return 0;
}

// <END-OF-CODE>
