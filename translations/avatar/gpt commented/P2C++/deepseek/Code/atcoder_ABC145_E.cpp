#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    // Read input from standard input
    int N, T;
    cin >> N >> T;

    // Initialize a vector to store time and value pairs, starting with a dummy entry
    vector<tuple<int, int>> time_value(N + 1, make_tuple(-1, -1));

    // Read the time and value pairs for each item
    for (int i = 1; i <= N; ++i) {
        int time, value;
        cin >> time >> value;
        time_value[i] = make_tuple(time, value);
    }

    // Sort the time_value vector based on the value (second element of the tuple)
    sort(time_value.begin() + 1, time_value.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<1>(a) < get<1>(b);
    });

    // Initialize a 2D vector for dynamic programming, with -1 as default values
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, -1));

    // Base case: If time is 0, the maximum value is 0 for all items
    for (int t = 0; t <= T; ++t) {
        dp[0][t] = 0;
    }

    // Fill the dynamic programming table
    for (int n = 1; n <= N; ++n) {
        // Base case: If no time is available, the maximum value is 0
        dp[n][0] = 0;
        for (int t = 1; t <= T; ++t) {
            // If the current item's time exceeds the available time, skip the item
            if (get<0>(time_value[n]) > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                // Choose the maximum between not taking the item and taking it
                dp[n][t] = max(dp[n - 1][t], get<1>(time_value[n]) + dp[n - 1][t - get<0>(time_value[n])]);
            }
        }
    }

    // Initialize the maximum value with the last item's value
    int val_acum = get<1>(time_value[N]);
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    // Backtrack to find the maximum value considering previous items
    for (int n = N - 1; n > 0; --n) {
        val_acum += get<1>(time_value[n]);
        t -= get<0>(time_value[n + 1]);

        // If time goes negative, break the loop
        if (t < 0) {
            break;
        } else {
            // Update the maximum value if a better option is found
            max_val = max(max_val, val_acum + dp[n - 1][t]);
        }
    }

    // Print the maximum value achievable within the given time
    cout << max_val << endl;

    return 0;
}
