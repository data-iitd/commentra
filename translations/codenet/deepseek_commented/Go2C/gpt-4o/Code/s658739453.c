#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n, p;
    scanf("%d", &n); // Read the value of n from standard input
    scanf("%d", &p); // Read the value of p from standard input

    int64_t *mdans = (int64_t *)calloc(p, sizeof(int64_t));
<<<<<<< HEAD
    int64_t *hash_map = (int64_t *)calloc(n + 1, sizeof(int64_t)); // To simulate a hash map

    for (int index = 0; index < p; index++) {
        int64_t n1;
        scanf("%lld", &n1); // Read each value into the hash_map
        if (n1 <= n) {
            hash_map[n1] = 1; // Mark the presence of n1
        }
=======
    for (int index = 0; index < p; index++) {
        scanf("%lld", &mdans[index]); // Read each value into the array mdans
>>>>>>> 98c87cb78a (data updated)
    }

    int64_t *dp = (int64_t *)calloc(n + 1, sizeof(int64_t));
    dp[0] = 1; // Initialize the first element of dp array
    dp[1] = 1; // Initialize the second element of dp array

<<<<<<< HEAD
    if (hash_map[1]) { // Check if the value 1 is in the hash_map
        dp[1] = 0; // Set dp[1] to 0 if 1 is in the hash_map
    }

    for (int i = 2; i <= n; i++) {
        if (hash_map[i]) { // Check if the current value i is in the hash_map
            continue; // Skip to the next iteration if i is in the hash_map
=======
    // Check if the value 1 is in the mdans array
    for (int index = 0; index < p; index++) {
        if (mdans[index] == 1) {
            dp[1] = 0; // Set dp[1] to 0 if 1 is in the array
            break;
        }
    }

    for (int i = 2; i <= n; i++) {
        int skip = 0;
        for (int index = 0; index < p; index++) {
            if (mdans[index] == i) {
                skip = 1; // Mark to skip this iteration if i is in the array
                break;
            }
        }
        if (skip) {
            continue; // Skip to the next iteration if i is in the array
>>>>>>> 98c87cb78a (data updated)
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD; // Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo MOD
    }

    printf("%lld\n", dp[n]); // Print the value at dp[n]

<<<<<<< HEAD
    free(mdans);
    free(hash_map);
    free(dp);
    
=======
    free(mdans); // Free the allocated memory for mdans
    free(dp);    // Free the allocated memory for dp
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
