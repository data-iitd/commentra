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
    return a * (b / gcd(a, b));
}

#define MOD 1000000007

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

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += pow_mod(A[i], MOD - 2, MOD);
    }
    ans = (_lcm * ans) % MOD;
    printf("%lld\n", ans);

    return 0;
}

// Function to perform modular exponentiation
int pow_mod(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
