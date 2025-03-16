#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor (gcd)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (lcm)
long long lcm(int a, int b) {
    return (long long)a * (b / gcd(a, b));
}

// Function to perform modular exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to calculate the modular inverse
long long mod_inv(long long x, long long mod) {
    return mod_pow(x, mod - 2, mod);
}

// Function to perform modular division
long long mod_div(long long a, long long b, long long mod) {
    return (a % mod) * mod_inv(b, mod) % mod;
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N];

    // Reading the integers into the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long lcm_val = 1;

    // Calculating the lcm of all integers in the array A
    for (int i = 0; i < N; i++) {
        lcm_val = lcm(lcm_val, A[i]);
    }

    long long mod = 1000000007;
    long long mod_lcm = lcm_val % mod;

    long long ans = 0;

    // Calculating the answer using modular arithmetic
    for (int i = 0; i < N; i++) {
        ans = (ans + mod_div(mod_lcm, A[i], mod)) % mod;
    }

    // Printing the answer
    printf("%lld\n", ans);

    return 0;
}
