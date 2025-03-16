#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compute the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to perform prime factorization of a number
void primeFactorize(int n, int *factors, int *counts) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            counts[i]++;
            factors[i] = 1; // Mark that this prime factor exists
        }
    }
    if (n > 1) {
        counts[n]++;
        factors[n] = 1; // Mark that this prime factor exists
    }
}

// Function to compute n raised to the power of k under modulo
int pow_mod(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return (1LL * pow_mod(n, k - 1) * n) % MOD;
    } else {
        int t = pow_mod(n, k / 2);
        return (1LL * t * t) % MOD;
    }
}

// Function to add two integers under modulo
int add(int a, int b) {
    return (a + b) % MOD;
}

// Function to multiply two integers under modulo
int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

// Function to divide two integers under modulo using modular multiplicative inverse
int div_mod(int a, int b) {
    return mul(a, pow_mod(b, MOD - 2));
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize an array to store the input numbers and arrays to store the maximum prime factors
    int *as = (int *)malloc(n * sizeof(int));
<<<<<<< HEAD
    int factors[100000] = {0}; // Assuming the maximum number is less than 100000
    int counts[100000] = {0};
=======
    int factors[100000] = {0}; // Assuming the maximum number of distinct prime factors is less than 100000
    int counts[100000] = {0}; // To count the occurrences of each prime factor
>>>>>>> 98c87cb78a (data updated)

    // Read each number and perform prime factorization
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        primeFactorize(as[i], factors, counts);
    }

    // Calculate the product of the maximum prime factors raised to their respective powers
    int x = 1;
    for (int i = 0; i < 100000; i++) {
        if (factors[i]) {
            for (int j = 0; j < counts[i]; j++) {
                x = mul(x, i);
            }
        }
    }

    // Calculate the final answer by summing the results of x divided by each input number
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div_mod(x, as[i]));
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free allocated memory
    free(as);

    return 0;
}

// <END-OF-CODE>
