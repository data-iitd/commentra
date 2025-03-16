#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Step 1: Read input values for v1, v2, t, and d.
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;

    // Step 2: Initialize a 2D array dp with dimensions (t-1) x 1150, and fill it with a very small value (-1e17).
    vector<vector<long long>> dp(t - 1, vector<long long>(1150, -1e17));
    
    // Step 3: Set the initial value of dp[0][v1] to v1.
    dp[0][v1] = v1;

    // Step 4: Iterate through the time steps from 1 to t-2.
    for (int i = 1; i < t - 1; i++) {
        // Step 5: For each time step, update the dp array based on the possible values of j (current position) and x (distance change).
        for (int j = 0; j < 1150; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < 1150) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j);
                }
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j);
                }
            }
        }
    }

    // Step 6: After updating the dp array, find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d.
    long long ans = LLONG_MIN;
    for (int j = 0; j < 1150; j++) {
        if (abs(j - v2) <= d) {
            ans = max(ans, dp[t - 2][j] + v2);
        }
    }

    // Step 7: Print the result.
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
