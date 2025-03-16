#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007LL

// Function to update the minimum value
void chmin(long long int *a, const long long int b) {
    if (*a > b) *a = b;
}

// Function to update the maximum value
void chmax(long long int *a, const long long int b) {
    if (*a < b) *a = b;
}

int main() {
    // Read the number of elements
    int n; 
    scanf("%d", &n);

    // Initialize an array to store the input values and an array for prefix sums
    long long int *a = (long long int *)malloc(n * sizeof(long long int));
    long long int *acc = (long long int *)malloc((n + 1) * sizeof(long long int));

    // Initialize prefix sum array
    acc[0] = 0;

    // Read input values and compute prefix sums modulo MOD
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        acc[i + 1] = acc[i] + a[i]; // Update prefix sum
        acc[i + 1] %= MOD; // Ensure the prefix sum is within MOD
    }

    // Initialize the answer variable
    long long int ans = 0;

    // Calculate the final answer using the prefix sums
    for (int i = 0; i < n; i++) {
        ans += (a[i] % MOD) * ((MOD + acc[n] - acc[i + 1]) % MOD); // Update answer based on current element and remaining sum
        ans %= MOD; // Ensure the answer is within MOD
    }

    // Output the final result
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);
    free(acc);

    return 0; // End of the program
}

// <END-OF-CODE>
