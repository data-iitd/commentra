#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to solve the problem
void solve() {
    // Input the number of elements
    long long n;
    scanf("%lld", &n);
    
    // Initialize the array to store the numbers
    long long *nums = (long long *)malloc(n * sizeof(long long));
    
    // Initialize variables to keep track of the last number and the previous index of the last number
    long long last = 0;
    for (long long i = 0; i < n; i++) {
        // Read the numbers from the input
        scanf("%lld", &nums[i]);
        // Update the last variable
        last = nums[i];
    }
    
    // Initialize a vector to store the prefix sum of the number of ways to reach each index
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    // Set the initial value of the prefix sum at index 0
    dp[0] = 1;
    
    // Initialize two maps to keep track of the previous index of each number and the number of ways to reach the previous index
    long long *kek = (long long *)calloc(1000001, sizeof(long long)); // Assuming numbers are in the range [0, 1000000]
    long long *prev = (long long *)calloc(1000001, sizeof(long long)); // Assuming numbers are in the range [0, 1000000]
    
    // Iterate through the numbers from 1 to n
    for (long long i = 1; i <= n; i++) {
        // Calculate the prefix sum at the current index
        dp[i] = dp[i - 1] + (prev[nums[i - 1]] != i - 1 ? kek[nums[i - 1]] : 0);
        dp[i] %= MOD;
        
        // Update the maps
        kek[nums[i - 1]] = dp[i];
        prev[nums[i - 1]] = i;
    }
    
    // Output the result
    printf("%lld\n", dp[n]);
    
    // Free allocated memory
    free(nums);
    free(dp);
    free(kek);
    free(prev);
}

// Main function to run the program
int main() {
    // Run the solve function
    solve();
    return 0;
}

// <END-OF-CODE>
