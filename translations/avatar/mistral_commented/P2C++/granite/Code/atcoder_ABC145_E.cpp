
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> time_value(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> time_value[i].second >> time_value[i].first;
    }

    time_value[0] = {0, 0};
    sort(time_value.begin(), time_value.end());

    vector<vector<int>> dp(N+1, vector<int>(T, 0));
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            if (time_value[n].second > t) {
                dp[n][t] = dp[n-1][t];
            } else {
                dp[n][t] = max(dp[n-1][t], time_value[n].first + dp[n-1][t-time_value[n].second]);
            }
        }
    }

    int val_acum = time_value[N].first;
    int t = T - 1;
    int max_val = val_acum + dp[N-1][t];

    for (int n = N-1; n >= 1; n--) {
        val_acum += time_value[n].first;
        t -= time_value[n+1].second;
        if (t < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[n-1][t]);
        }
    }

    cout << max_val << endl;

    return 0;
}
