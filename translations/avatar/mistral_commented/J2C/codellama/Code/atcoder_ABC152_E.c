#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A function to calculate the greatest common divisor (gcd) of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// A function to calculate the least common multiple (lcm) of two integers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// A function to calculate the modular inverse of a number
int modInv(int x, int mod) {
    return modPow(x, mod - 2, mod);
}

// A function to calculate the power of a number using modular arithmetic
int modPow(int b, int e, int mod) {
    int ans = 1;
    int x = b % mod;
    for (int y = e; y != 0; y >>= 1) {
        if (y & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
    }
    return ans;
}

// A function to calculate the modular division of two integers
int modDiv(int a, int b, int mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int lcm = 1;
    for (int i = 0; i < N; i++) {
        lcm = lcm / gcd(lcm, A[i]) * A[i];
    }

    int mod = 1000000007;
    int modLcm = lcm % mod;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }

    printf("%d\n", ans);

    return 0;
}

