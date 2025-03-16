#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to perform modular exponentiation
long long mod_pow(long long b, long long e, long long mod) {
    long long ans = 1;
    long long x = b % mod;
    while (e > 0) {
        if (e % 2 == 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        e /= 2;
    }
    return ans;
}

// Function to calculate modular inverse
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
    long long A[N];

    // Read N integers into array A
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize LCM to 1
    long long lcm = 1;

    // Calculate the LCM of all elements in array A
    for (int i = 0; i < N; i++) {
        long long a = A[i];
        lcm = (lcm / gcd(lcm, a)) * a;
    }

    // Define the modulo value
    long long mod = 1000000007;

    // Calculate the LCM modulo 10^9 + 7
    long long mod_lcm = lcm % mod;

    // Initialize the answer to 0
    long long ans = 0;

    // Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for (int i = 0; i < N; i++) {
        ans = (ans + mod_div(mod_lcm, A[i], mod)) % mod;
    }

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}
