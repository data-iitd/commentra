#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

int gcd(int a, int b) {
    // Calculate the greatest common divisor (GCD) of two numbers a and b
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    // Calculate the least common multiple (LCM) of two numbers a and b
    return a * b / gcd(a, b);
}

int main() {
    int N, i, _lcm = 1;
    scanf("%d", &N);
    int A[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);
    }
    int ans = _lcm * (pow(A[0], MOD - 2) % MOD);
    for (i = 1; i < N; i++) {
        ans = (ans * pow(A[i], MOD - 2) % MOD) * A[i - 1] % MOD;
    }
    printf("%d", ans);
    return 0;
}

