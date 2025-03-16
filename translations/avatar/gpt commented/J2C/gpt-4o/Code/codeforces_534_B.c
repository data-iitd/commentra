#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_VELOCITY 1150
#define MAX_TIME 1000 // Adjust this if needed based on constraints

int main() {
    // Read four integers from input: initial velocity (v1), final velocity (v2), time (t), and maximum change in velocity (d)
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);
    
    // Initialize a 2D array dp to store the maximum values for each time step and velocity
    long long dp[MAX_TIME][MAX_VELOCITY];
    
    // Fill the dp array with a very small value to represent uninitialized states
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            dp[i][j] = LLONG_MIN; // Use LLONG_MIN for long long minimum value
        }
    }
    
    // Set the initial state for the first time step with the initial velocity
    dp[0][v1] = v1;
    
    // Variable to accumulate the maximum sum of velocities
    long long sum = 0;
    
    // Iterate through each time step from 1 to t-2
    for (int i = 1; i < t - 1; i++) {
        // Iterate through each possible velocity
        for (int j = 0; j < MAX_VELOCITY; j++) {
            // Update the dp array for increasing velocities
            for (int x = 0; x <= d; x++) {
                if (j + x < MAX_VELOCITY) {
                    dp[i][j] = (dp[i][j] > dp[i - 1][j + x] + j) ? dp[i][j] : (dp[i - 1][j + x] + j);
                }
            }
            // Update the dp array for decreasing velocities
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = (dp[i][j] > dp[i - 1][j - x] + j) ? dp[i][j] : (dp[i - 1][j - x] + j);
                }
            }
        }
    }
    
    // Variable to store the final answer, initialized to the smallest possible value
    long long ans = LLONG_MIN;
    
    // Iterate through the last time step to find the maximum achievable velocity close to v2
    for (int j = 0; j < MAX_VELOCITY; j++) {
        // Check if the current velocity is within the allowed range of v2
        if (abs(j - v2) <= d) {
            ans = (ans > dp[t - 2][j] + v2) ? ans : (dp[t - 2][j] + v2);
        }
    }
    
    // Output the final answer
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
