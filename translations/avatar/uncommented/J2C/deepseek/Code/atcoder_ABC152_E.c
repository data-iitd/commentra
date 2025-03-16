#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mod_pow(long long b, long long e, long long mod) {
    long long ans = 1;
    long long x = b % mod;
    while (e > 0) {
        if (e % 2 == 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        e /= 2;
    }
    return ans;
}

long long mod_inv(long long x, long long mod) {
    return mod_pow(x, mod - 2, mod);
}

long long mod_div(long long a, long long b, long long mod) {
    return (a % mod) * mod_inv(b, mod) % mod;
}

int main() {
    int N;
    scanf("%d", &N);
    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long lcm = 1;
    for (int i = 0; i < N; i++) {
        long long a = A[i];
        lcm = lcm / gcd(lcm, a) * a;
    }

    long long mod = 1000000007;
    long long mod_lcm = lcm % mod;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + mod_div(mod_lcm, A[i], mod)) % mod;
    }
    printf("%lld\n", ans);

    return 0;
}
