#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to perform prime factorization of a number
int* primeFactorize(int n, int* size) {
    int limit = (int)sqrt(n);
    int* factors = (int*)malloc(1000 * sizeof(int)); // Allocate memory for factors
    *size = 0; // Initialize size of factors array

    // Check for factors from 2 up to the square root of n
    for (int i = 2; i <= limit; i++) {
        // While i is a factor of n, divide n by i and count the occurrences
        while (n % i == 0) {
            factors[(*size)++] = i;
            n /= i;
        }
    }
    // If n is still greater than 1, it is a prime factor itself
    if (n > 1) {
        factors[(*size)++] = n;
    }
    return factors;
}

// Define a constant for the modulo operation
const int mod = 1000000007;

// Function to compute n raised to the power of k under modulo
int pow(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow(n, k - 1) * n % mod;
    } else {
        int t = pow(n, k / 2);
        return t * t % mod;
    }
}

// Function to add two integers under modulo
int add(int a, int b) {
    return (a + b) % mod;
}

// Function to subtract two integers under modulo
int sub(int a, int b) {
    return (a + mod - b) % mod;
}

// Function to multiply two integers under modulo
int mul(int a, int b) {
    return a % mod * b % mod % mod;
}

// Function to divide two integers under modulo using modular multiplicative inverse
int div(int a, int b) {
    return mul(a, pow(b, mod - 2));
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize an array to store the input numbers and a map to store the maximum prime factors
    int* as = (int*)malloc(n * sizeof(int));
    int* ps = (int*)malloc(1000 * sizeof(int));
    int psSize = 0;

    // Read each number and perform prime factorization
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);

        // Get the prime factors of the current number
        int* ns = primeFactorize(as[i], &psSize);
        // Update the maximum count of each prime factor found
        for (int j = 0; j < psSize; j++) {
            int found = 0;
            for (int k = 0; k < psSize; k++) {
                if (ps[k] == ns[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                ps[psSize++] = ns[j];
            }
        }
        free(ns); // Free the memory allocated for ns
    }

    // Calculate the product of the maximum prime factors raised to their respective powers
    int x = 1;
    for (int i = 0; i < psSize; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            int temp = as[j];
            int tempCount = 0;
            while (temp % ps[i] == 0) {
                temp /= ps[i];
                tempCount++;
            }
            if (tempCount > count) {
                count = tempCount;
            }
        }
        for (int j = 0; j < count; j++) {
            x = mul(x, ps[i]);
        }
    }

    // Calculate the final answer by summing the results of x divided by each input number
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, as[i]));
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free allocated memory
    free(as);
    free(ps);

    return 0;
}
