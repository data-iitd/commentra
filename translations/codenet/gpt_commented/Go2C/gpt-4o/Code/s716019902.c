#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define FAC_NUM 300001

// Function to calculate power under modulo
int pow_mod(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * 1LL * a) % MOD; // Multiply by a if n is odd
        }
        a = (a * 1LL * a) % MOD; // Square a
        n >>= 1; // Right shift n
    }
    return ans; // Return the result
}

// Function to calculate GCD
int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a); // Ensure a is greater than b
    }
    while (b != 0) {
        int temp = b;
<<<<<<< HEAD
        b = a % b; // Apply Euclidean algorithm
        a = temp;
=======
        b = a % b;
        a = temp; // Apply Euclidean algorithm
>>>>>>> 98c87cb78a (data updated)
    }
    return a; // Return the GCD
}

// Function to calculate factorials and their modular inverses
void factorial(int fac[], int ifac[]) {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < FAC_NUM; i++) {
        fac[i] = (fac[i - 1] * 1LL * i) % MOD; // Compute factorial
        ifac[i] = (ifac[i - 1] * 1LL * pow_mod(i, MOD - 2)) % MOD; // Compute inverse factorial
    }
}

// Function to calculate n choose k using precomputed factorials
int combination(int n, int k, int fac[], int ifac[]) {
    if (n < k || n < 0) {
        return 0; // Return 0 if invalid
    }
    if (k == 0) {
        return 1; // Return 1 if k is 0
    }
    // Calculate combination using factorials
    return (ifac[k] * 1LL * ifac[n - k] % MOD) * fac[n] % MOD;
}

int main() {
    int N;
    scanf("%d", &N); // Read an integer N from input
    int sum = 0;

    // Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue; // Skip numbers divisible by 3 or 5
        }
        sum += i; // Add the number to the sum
    }

    // Output the final sum
    printf("%d\n", sum);
    return 0;
}

<<<<<<< HEAD
/* <END-OF-CODE> */
=======
// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
