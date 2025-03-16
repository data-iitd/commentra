#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_VELOCITY 1150
#define MIN_VALUE -1000000000000000000LL

int main() {
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);
    
    // Initialize a 2D array dp with dimensions (t-1) x MAX_VELOCITY
    long long dp[t - 1][MAX_VELOCITY];
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            dp[i][j] = MIN_VALUE;
        }
    }
    
    // Set the initial value of dp[0][v1] to v1
    dp[0][v1] = v1;
    
    // Iterate through the time steps from 1 to t-2
    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < MAX_VELOCITY; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < MAX_VELOCITY) {
                    dp[i][j] = dp[i][j] > dp[i - 1][j + x] + j ? dp[i][j] : dp[i - 1][j + x] + j;
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = dp[i][j] > dp[i - 1][j - x] + j ? dp[i][j] : dp[i - 1][j - x] + j;
                }
            }
        }
    }
    
    // Find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d
    long long ans = LLONG_MIN;
    for (int j = 0; j < MAX_VELOCITY; j++) {
        if (abs(j - v2) <= d) {
            ans = ans > dp[t - 2][j] + v2 ? ans : dp[t - 2][j] + v2;
        }
    }
    
    // Print the result
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
