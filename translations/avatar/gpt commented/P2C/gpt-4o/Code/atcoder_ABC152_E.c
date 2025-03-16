#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}

long long mod_inverse(long long a, long long mod) {
    long long m0 = mod, t, q;
    long long x0 = 0, x1 = 1;

    if (mod == 1) return 0;

    while (a > 1) {
        q = a / mod;
        t = mod;

        mod = a % mod;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

int main() {
    const long long MOD = 1000000007;
    int N;
    scanf("%d", &N);
    
    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long _lcm = 1;
    for (int i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);
    }

    long long sum_inverses = 0;
    for (int i = 0; i < N; i++) {
        sum_inverses = (sum_inverses + mod_inverse(A[i], MOD)) % MOD;
    }

    long long ans = (_lcm * sum_inverses) % MOD;

    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
