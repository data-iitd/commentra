#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int max(int a, int b) {
    return (a > b) ? a : b;
}

void primeFactorize(int n, int *factors, int *powers) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            factors[i]++;
        }
    }
    if (n != 1) {
        factors[n]++;
    }
}

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

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a + MOD - b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int div_mod(int a, int b) {
    return mul(a, pow_mod(b, MOD - 2));
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    int *as = (int *)malloc(n * sizeof(int));
<<<<<<< HEAD
    int *factors = (int *)calloc(1000000, sizeof(int)); // Assuming a reasonable limit for prime factors
    int *powers = (int *)calloc(1000000, sizeof(int)); // To store the powers of prime factors
=======
    int factors[100000] = {0}; // Assuming the maximum number of distinct prime factors is less than 100000
>>>>>>> 98c87cb78a (data updated)

    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]); // Read each element of the array

<<<<<<< HEAD
        primeFactorize(as[i], factors, powers); // Prime factorize the current element
    }

    int x = 1;
    for (int i = 0; i < 1000000; i++) {
        if (factors[i] > 0) {
            for (int j = 1; j <= factors[i]; j++) {
                x = mul(x, i); // Calculate the LCM by multiplying the prime factors with their powers
=======
        int temp_factors[100000] = {0}; // Temporary array to store prime factors
        primeFactorize(as[i], temp_factors, factors); // Prime factorize the current element

        for (int j = 0; j < 100000; j++) {
            factors[j] = max(factors[j], temp_factors[j]); // Update the factors with the maximum powers
        }
    }

    int x = 1;
    for (int k = 0; k < 100000; k++) {
        if (factors[k] > 0) {
            for (int i = 1; i <= factors[k]; i++) {
                x = mul(x, k); // Calculate the LCM by multiplying the prime factors with their powers
>>>>>>> 98c87cb78a (data updated)
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div_mod(x, as[i])); // Calculate the sum of modular inverses
    }
    printf("%d\n", ans); // Print the final answer

<<<<<<< HEAD
    free(as);
    free(factors);
    free(powers);
=======
    free(as); // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
