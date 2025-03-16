

#include <stdio.h>

#define d 1000000007

int main() {
    int n, p;
    scanf("%d", &n); // Read the value of n from standard input
    scanf("%d", &p); // Read the value of p from standard input

    long mdans[p];
    for (int index = 0; index < p; index++) {
        scanf("%ld", &mdans[index]); // Read each value into the array mdans
    }

    long dp[n+1];
    dp[0] = 1; // Initialize the first element of dp array
    dp[1] = 1; // Initialize the second element of dp array

    for (int i = 2; i <= n; i++) {
        int found = 0;
        for (int j = 0; j < p; j++) {
            if (i == mdans[j]) { // Check if the current value i is in the array mdans
                found = 1; // Set found to 1 if i is in the array
                break; // Exit the loop if i is found in the array
            }
        }
        if (found == 0) { // Check if i is not found in the array mdans
            dp[i] = (dp[i-1] + dp[i-2]) % d; // Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo d
        }
    }

    printf("%ld\n", dp[n]); // Print the value at dp[n]

    return 0;
}

