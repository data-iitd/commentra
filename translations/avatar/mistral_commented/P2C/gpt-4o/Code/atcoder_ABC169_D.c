#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define INF 999999999999999999
#define MOD 1000000007

// Function to prime factorize a number
void prime_factorize(long long n, int *factors, int *count) {
    while (n % 2 == 0) {
        factors[(*count)++] = 2;
        n /= 2;
    }
    for (long long f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            factors[(*count)++] = f;
            n /= f;
        }
    }
    if (n > 1) {
        factors[(*count)++] = n;
    }
}

int main() {
    // Set recursion limit (not applicable in C like in Python)
    
    // Get the number of test cases
    int n;
    scanf("%d", &n);

    // Base case for the recursion
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    // Initialize variables
    int factors[100]; // Array to store prime factors
    int count = 0; // Count of prime factors
    prime_factorize(n, factors, &count);

    // Count the occurrences of each prime factor
    int fac[100] = {0}; // Array to store the count of each prime factor
    for (int i = 0; i < count; i++) {
        fac[factors[i]]++;
    }

    long long ans = 0;

    // Calculate the answer
    for (int i = 0; i < 100; i++) {
        if (fac[i] > 0) {
            int x = fac[i];
            for (int j = 1; j < INT_MAX; j++) {
                if (x >= j) {
                    x -= j;
                    ans++;
                } else {
                    break;
                }
            }
        }
    }

    // Print the answer
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
