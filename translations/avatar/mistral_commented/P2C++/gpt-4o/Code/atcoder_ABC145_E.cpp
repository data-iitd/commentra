#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define constants for TIME and VAL
const int TIME = 0;
const int VAL = 1;

int main() {
    // Initialize variables
    int N, T;
    cin >> N >> T;

    // Initialize time_value vector
    vector<pair<int, int>> time_value(N + 1, make_pair(-1, -1));

    // Read time_value for each activity
    for (int i = 1; i <= N; ++i) {
        int start, value;
        cin >> start >> value;
        time_value[i] = make_pair(start, value);
    }

    // Sort time_value based on their VAL (end time)
    sort(time_value.begin() + 1, time_value.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // Initialize dp matrix
    vector<vector<int>> dp(N + 1, vector<int>(T, -1));

    // Initialize first row and column of dp matrix
    for (int t = 0; t < T; ++t) {
        dp[0][t] = 0;
    }
    dp[0][0] = 0;
    for (int n = 1; n <= N; ++n) {
        dp[n][0] = 0;
    }

    // Fill dp matrix
    for (int n = 1; n <= N; ++n) {
        for (int t = 1; t < T; ++t) {
            // If current activity's start time is greater than t, then we cannot include it in the solution
            if (time_value[n].first > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                // If current activity's start time is less than or equal to t, then we can include it in the solution
                dp[n][t] = max(dp[n - 1][t], time_value[n].second + dp[n - 1][t - time_value[n].first]);
            }
        }
    }

    // Calculate maximum value that can be obtained
    int val_acum = time_value[N].second;
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    // Calculate maximum value by considering all activities
    for (int n = N - 1; n > 0; --n) {
        val_acum += time_value[n].second;
        t -= time_value[n + 1].first;
        if (t < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[n - 1][t]);
        }
    }

    // Print the maximum value
    cout << max_val << endl;

    return 0;
}

// <END-OF-CODE>
