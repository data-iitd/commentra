
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a vector to store the maximum values for each time step and velocity
    vector<vector<long>> dp(1000, vector<long>(1150, -1e17));

    // Read four integers from input: initial velocity (v1), final velocity (v2), time (t), and maximum change in velocity (d)
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    // Set the initial state for the first time step with the initial velocity
    dp[0][v1] = v1;

    // Variable to accumulate the maximum sum of velocities
    long sum = 0;

    // Iterate through each time step from 1 to t-2
    for (int i = 1; i < t - 1; i++) {
        // Iterate through each possible velocity
        for (int j = 0; j < 1150; j++) {
            // Update the dp array for increasing velocities
            for (int x = 0; x <= d; x++) {
                if (j + x < 1150)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j);
            }
            // Update the dp array for decreasing velocities
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j);
                }
            }
        }
    }

    // Variable to store the final answer, initialized to the smallest possible value
    long ans = LLONG_MIN;

    // Iterate through the last time step to find the maximum achievable velocity close to v2
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            // Check if the current velocity is within the allowed range of v2
            if (abs(j - v2) <= d)
                ans = max(ans, dp[i][j] + v2);
        }
    }

    // Output the final answer
    cout << ans << endl;

    return 0;
}

