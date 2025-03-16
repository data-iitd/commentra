#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int main() {
    int v1, v2, t, d;
    std::cin >> v1 >> v2 >> t >> d;

    // Step 1: Initialize a 2D vector dp with dimensions (t-1) x 1150, and fill it with a very small value (-1e17).
    std::vector<std::vector<long long>> dp(t - 1, std::vector<long long>(1150, -1e17));

    // Step 2: Set the initial value of dp[0][v1] to v1.
    dp[0][v1] = v1;

    // Step 3: Iterate through the time steps from 1 to t-2.
    for (int i = 1; i < t - 1; i++) {
        // Step 4: For each time step, update the dp array based on the possible values of j (current position) and x (distance change).
        for (int j = 0; j < 1150; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < 1150) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j + x] + j);
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = std.max(dp[i][j], dp[i - 1][j - x] + j);
                }
            }
        }
    }

    // Step 5: After updating the dp array, find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d.
    long long ans = LLONG_MIN;
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            if (std::abs(j - v2) <= d) {
                ans = std::max(ans, dp[i][j] + v2);
            }
        }
    }

    // Step 6: Print the result.
    std::cout << ans << std::endl;

    return 0;
}
