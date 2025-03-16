#include <stdio.h>
#include <stdlib.h>

// Constants
const int mod = 998244353;
const int facNum = 300001;

// Function to read an integer from standard input
int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to calculate a^n modulo mod
int powMod(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        n >>= 1;
    }
    return ans;
}

// Function to calculate the greatest common divisor of a and b
int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the factorial and inverse factorial
void factorial(int *fac, int *ifac) {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = (fac[i - 1] * 1LL * i) % mod;
        ifac[i] = (ifac[i - 1] * 1LL * powMod(i, mod - 2)) % mod;
    }
}

// Function to calculate the binomial coefficient (n choose k) modulo mod
int combination(int n, int k, int *fac, int *ifac) {
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    return (ifac[k] * 1LL * ifac[n - k] % mod) * fac[n] % mod;
}

// Main function
int main() {
    // Read an integer N from the standard input
    int N = readInt();

    // Initialize a variable sum to 0
    long long sum = 0;

    // Loop through numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        // If the number is not divisible by 3 or 5, add it to the sum
        if (i % 3 != 0 && i % 5 != 0) {
            sum += i;
        }
    }

    // Print the result to the standard output
    printf("%lld\n", sum);

    return 0;
}

// <END-OF-CODE>
