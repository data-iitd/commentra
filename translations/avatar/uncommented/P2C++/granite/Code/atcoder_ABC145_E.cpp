
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> time_value(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> time_value[i].second >> time_value[i].first;
    }
    time_value[0] = {0, 0};
    sort(time_value.begin(), time_value.end());
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (time_value[i].first > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], time_value[i].second + dp[i - 1][j - time_value[i].first]);
            }
        }
    }
    int val_acum = time_value[n].second;
    int max_val = val_acum + dp[n - 1][t - time_value[n].first];
    for (int i = n - 1; i > 0; i--) {
        val_acum += time_value[i].second;
        t -= time_value[i + 1].first;
        if (t < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[i - 1][t]);
        }
    }
    cout << max_val << endl;
    return 0;
}

