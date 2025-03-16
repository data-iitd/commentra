#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int TIME = 0;
const int VAL = 1;

int main() {
    // Reading Input: The code starts by reading the number of items N and the maximum time T.
    int N, T;
    cin >> N >> T;

    // Initializing Data Structures: It initializes a vector time_value to store the time and value of each item.
    vector<pair<int, int>> time_value(N + 1);
    time_value[0] = make_pair(-1, -1); // Placeholder at index 0

    // Reading Item Details: It reads the time and value for each item and stores them in time_value.
    for (int i = 1; i <= N; ++i) {
        int time, value;
        cin >> time >> value;
        time_value[i] = make_pair(time, value);
    }

    // Sorting Items: The items are sorted based on their value.
    sort(time_value.begin(), time_value.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // Sort by value
    });

    // Dynamic Programming Table Initialization: A 2D vector dp is initialized to store the maximum value.
    vector<vector<int>> dp(N + 1, vector<int>(T, -1));

    // Base Cases for DP Table: The base cases are set where no time means no value.
    for (int t = 0; t < T; ++t) {
        dp[0][t] = 0;
    }

    for (int n = 1; n <= N; ++n) {
        dp[n][0] = 0;
        for (int t = 1; t < T; ++t) {
            if (time_value[n].first > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                dp[n][t] = max(dp[n - 1][t], time_value[n].second + dp[n - 1][t - time_value[n].first]);
            }
        }
    }

    // Calculating Maximum Value: The maximum value is calculated by considering the last item and reducing the time accordingly.
    int val_acum = time_value[N].second;
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];

    for (int n = N - 1; n > 0; --n) {
        val_acum += time_value[n].second;
        t -= time_value[n + 1].first;
        if (t < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[n - 1][t]);
        }
    }

    // Printing Result: The final maximum value is printed.
    cout << max_val << endl;

    return 0;
}

// <END-OF-CODE>
