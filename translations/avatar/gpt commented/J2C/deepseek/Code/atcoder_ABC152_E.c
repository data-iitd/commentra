#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Function to perform modular division
long long mod_div(long long a, long long b, long long mod) {
    return (a % mod) * mod_pow(b, mod - 2, mod) % mod;
}

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int A[N];
    printf("Enter %d elements: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long lcm_value = 1;
    for (int i = 0; i < N; i++) {
        lcm_value = lcm(lcm_value, A[i]);
    }

    long long mod = 1000000007;
    long long mod_lcm = lcm_value % mod;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + mod_div(mod_lcm, A[i], mod)) % mod;
    }

    printf("Result: %lld\n", ans);

    return 0;
}
