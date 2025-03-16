#include <stdio.h>
#include <stdlib.h>

long long modPow(long long b, long long e, long long mod) {
    long long ans = 1;
    long long x = b % mod;
    while (e != 0) {
        if (e & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        e >>= 1;
    }
    return ans;
}

long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long lcmValue = 1;
    for (int i = 0; i < N; i++) {
        lcmValue = lcm(lcmValue, A[i]);
    }

    long long mod = 1000000007;
    long long modLcm = lcmValue % mod;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }

    printf("%lld\n", ans);
    free(A);
    return 0;
}

// <END-OF-CODE>
