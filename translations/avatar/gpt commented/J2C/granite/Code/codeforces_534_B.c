
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the user
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);

    // Initialize a 2D array dp to store the maximum values for each time step and velocity
    long long dp[t - 1][1150];
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            dp[i][j] = -1;
        }
    }

    // Set the initial state for the first time step with the initial velocity
    dp[0][v1] = v1;

    // Variable to accumulate the maximum sum of velocities
    long long sum = 0;

    // Iterate through each time step from 1 to t-2
    for (int i = 1; i < t - 1; i++) {
        // Iterate through each possible velocity
        for (int j = 0; j < 1150; j++) {
            // Update the dp array for increasing velocities
            for (int x = 0; x <= d; x++) {
                if (j + x < 1150) {
                    dp[i][j] = dp[i - 1][j + x] + j;
                }
            }
            // Update the dp array for decreasing velocities
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = dp[i - 1][j - x] + j;
                }
            }
        }
    }

    // Variable to store the final answer, initialized to the smallest possible value
    long long ans = -1;

    // Iterate through the last time step to find the maximum achievable velocity close to v2
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            // Check if the current velocity is within the allowed range of v2
            if (abs(j - v2) <= d) {
                ans = dp[i][j] + v2;
            }
        }
    }

    // Output the final answer
    printf("%lld\n", ans);

    return 0;
}
