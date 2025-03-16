#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int _lcm = 1;
    for (int i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);
    }

    int ans = _lcm * (pow(A[0], MOD - 2) % MOD);
    for (int i = 1; i < N; i++) {
        ans = (ans + _lcm * (pow(A[i], MOD - 2) % MOD)) % MOD;
    }

    printf("%d", ans);

    return 0;
}

