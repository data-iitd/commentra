#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    long long lcm = 1;
    for (int i = 0; i < N; i++) {
        lcm = lcm / __gcd(lcm, A[i]) * A[i];
    }
    long long mod = 1000000007;
    long long modLcm = lcm % mod;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

long long modPow(long long b, long long e, long long mod) {
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

