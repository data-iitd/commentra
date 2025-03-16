#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007 // Define a constant 'MOD'

// Function to check if a number exists in the array
int exists(int *arr, int size, long long n1) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n1) {
            return 1; // Return 1 if the number exists
        }
    }
    return 0; // Return 0 if the number does not exist
}

int main() {
    // Initialize variables
    int n, p;

    scanf("%d", &n); // Read the first integer 'n' from the standard input
    scanf("%d", &p); // Read the second integer 'p' from the standard input

    long long *mdans = (long long *)malloc(p * sizeof(long long)); // Allocate memory for 'mdans'
    
    // Read 'p' distinct numbers from the standard input and store them in the array 'mdans'
    for (int index = 0; index < p; index++) {
        scanf("%lld", &mdans[index]);
    }

    long long *dp = (long long *)malloc((n + 1) * sizeof(long long)); // Allocate memory for 'dp'
    dp[0] = 1; // Initialize the first element of the array 'dp' with a value of '1'
    dp[1] = 1; // Initialize the second element of the array 'dp' with a value of '1'

    // Initialize the second element of the array 'dp' with a value of '0' if the number '1' is present in the array 'mdans'
    if (exists(mdans, p, 1)) {
        dp[1] = 0;
    }

    // Calculate the remaining elements of the array 'dp' using the previous elements
    for (int i = 2; i <= n; i++) {
        if (exists(mdans, p, i)) {
            continue; // Skip the current iteration if the number 'i' is present in the array 'mdans'
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD; // Calculate the current element of the array 'dp'
    }

    // Print the final result
    printf("%lld\n", dp[n]); // Print the value of the last element of the array 'dp'

    // Free allocated memory
    free(mdans);
    free(dp);

    return 0;
}
