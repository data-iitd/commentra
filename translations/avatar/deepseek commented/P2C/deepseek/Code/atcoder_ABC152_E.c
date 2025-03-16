#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM)
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long _lcm = 1;
    for (int i = 0; i < N; i++) {
        _lcm = _lcm * A[i] / gcd(_lcm, A[i]);
    }

    long long ans = _lcm;
    for (int i = 0; i < N; i++) {
        ans = (ans + MOD - _lcm * gcd(_lcm, A[i]) % MOD * pow(A[i], MOD - 2) % MOD) % MOD;
    }

    printf("%lld\n", ans % MOD);
    return 0;
}

