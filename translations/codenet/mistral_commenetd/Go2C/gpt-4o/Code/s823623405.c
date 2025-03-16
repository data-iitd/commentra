#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate n raised to the power of k modulo mod
int pow_mod(int n, int k) {
    if (k == 0) return 1;
    if (k % 2 == 1) return (1LL * pow_mod(n, k - 1) * n) % MOD;
    int t = pow_mod(n, k / 2);
    return (1LL * t * t) % MOD;
}

// Function to add two integers modulo mod
int add(int a, int b) {
    return (a + b) % MOD;
}

// Function to subtract two integers modulo mod
int sub(int a, int b) {
    return (a + MOD - b) % MOD;
}

// Function to multiply two integers modulo mod
int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

// Function to divide a by b modulo mod
int div_mod(int a, int b) {
    return mul(a, pow_mod(b, MOD - 2));
}

// Function to calculate the prime factors and their powers of a given integer
void primeFactorize(int n, int *factors, int *powers, int *size) {
    *size = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors[*size] = i;
            powers[*size] = 0;
            while (n % i == 0) {
                n /= i;
                powers[*size]++;
            }
            (*size)++;
        }
    }
    if (n > 1) {
        factors[*size] = n;
        powers[*size] = 1;
        (*size)++;
    }
}

int main() {
    // Initialize variables
    int n;
    scanf("%d", &n); // Read the number of integers from the standard input
    int *as = (int *)malloc(n * sizeof(int)); // Create an array to store the input integers
    int factors[100]; // Array to store prime factors (assuming a maximum of 100 different prime factors)
    int powers[100]; // Array to store the powers of the prime factors
    int ps[100] = {0}; // Array to store the maximum powers of prime factors
    int size;

    // Read the input integers and calculate their prime factors
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]); // Read an integer from the standard input
        primeFactorize(as[i], factors, powers, &size); // Calculate the prime factors and their powers
        for (int j = 0; j < size; j++) { // Update the powers of the prime factors
            ps[factors[j]] = max(ps[factors[j]], powers[j]);
        }
    }

    // Calculate the answer
    int x = 1; // Initialize a variable to store the product of prime factors
    for (int i = 0; i < 100; i++) { // Iterate through the array to calculate the product of prime factors
        if (ps[i] > 0) {
            for (int j = 1; j <= ps[i]; j++) { // Calculate the power of the prime factor
                x = mul(x, i); // Multiply the current product with the prime factor
            }
        }
    }

    int ans = 0; // Initialize a variable to store the answer
    for (int i = 0; i < n; i++) { // Iterate through the array to calculate the answer
        ans = add(ans, div_mod(x, as[i])); // Calculate the difference and add it to the answer
    }

    printf("%d\n", ans); // Print the answer
    free(as); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
