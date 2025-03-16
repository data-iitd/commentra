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
    long long int lcm = 1;
    for (int i = 0; i < N; i++) {
        long long int a = A[i];
        lcm = lcm / __gcd(lcm, a) * a;
    }
    long long int mod = 1000000007;
    long long int modLcm = lcm % mod;
    long long int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

long long int modDiv(long long int a, long long int b, long long int mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

long long int modInv(long long int x, long long int mod) {
    return modPow(x, mod - 2, mod);
}

long long int modPow(long long int b, long long int e, long long int mod) {
    long long int ans = 1;
    long long int x = b % mod;
    for (long long int y = e; y!= 0; y >>= 1) {
        if ((y & 1) == 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
    }
    return ans;
}

