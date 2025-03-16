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
    long long m0 = mod, y = 0, x = 1;
    if (mod == 1) return 0;
    while (a > 1) {
        long long q = a / mod;
        long long t = mod;
        mod = a % mod, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
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

    long long sum_inverse = 0;
    for (int i = 0; i < N; i++) {
        sum_inverse = (sum_inverse + mod_inverse(A[i], MOD)) % MOD;
    }

    long long ans = (_lcm * sum_inverse) % MOD;
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
