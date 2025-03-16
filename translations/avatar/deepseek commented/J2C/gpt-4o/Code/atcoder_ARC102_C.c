#include <stdio.h>

#define MOD 998244353
#define MAX 4001

long nchoosek[MAX][MAX];

void initialize_nchoosek() {
    for (int i = 0; i < MAX; i++) {
        nchoosek[i][0] = nchoosek[i][i] = 1; // nchoosek[i][0] and nchoosek[i][i] are 1
    }

    // Fill the nchoosek array using dynamic programming
    for (int i = 2; i < MAX; i++) {
        for (int j = 1; j < i; j++) {
            nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    initialize_nchoosek(); // Initialize the nchoosek array

    int k, n;
    scanf("%d %d", &k, &n); // Read input values k and n

    // Main loop to compute and print results for each i from 2 to 2*k
    for (int i = 2; i <= 2 * k; i++) {
        int pairs;
        if (i > k) {
            pairs = k - i / 2; // Calculate pairs based on i
        } else {
            pairs = (i - 1) / 2; // Calculate pairs based on i
        }
        int active = k - 2 * pairs; // Calculate active elements
        if (i % 2 == 0) active -= 1; // Adjust active if i is even

        long times2 = 1; // Initialize times2 for calculating powers of 2
        long total = 0; // Initialize total for storing the result

        // Calculate total using binomial coefficients
        for (int j = 0; j <= pairs; j++) {
            long choice = times2 * nchoosek[pairs][j] % MOD; // Calculate choice
            times2 = times2 * 2 % MOD; // Update times2
            if (active + j - 1 < 0) continue; // Skip if invalid
            total += choice * nchoosek[n + active - 1][active + j - 1]; // Add to total
            total %= MOD; // Ensure total is within the modulo
            if (i % 2 == 0) {
                total += choice * nchoosek[n + active - 2][active + j - 1]; // Add for even i
                total %= MOD; // Ensure total is within the modulo
            }
        }
        printf("%ld\n", total); // Print the result
    }

    return 0;
}

// <END-OF-CODE>
