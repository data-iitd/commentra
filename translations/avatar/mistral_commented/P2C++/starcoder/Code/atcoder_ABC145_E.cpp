#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T;
    cin >> N >> T;

    vector<tuple<int, int>> time_value(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> get<0>(time_value[i]) >> get<1>(time_value[i]);
    }

    sort(time_value.begin() + 1, time_value.end(), [](tuple<int, int> a, tuple<int, int> b) {
        return get<1>(a) < get<1>(b);
    });

    vector<vector<int>> dp(N+1, vector<int>(T+1, -1));
    for (int t = 0; t <= T; t++) {
        dp[0][t] = 0;
    }
    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
    }

    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            if (get<0>(time_value[n]) > t) {
                dp[n][t] = dp[n-1][t];
            } else {
                dp[n][t] = max(dp[n-1][t], get<1>(time_value[n]) + dp[n-1][t-get<0>(time_value[n])]);
            }
        }
    }

    int val_acum = get<1>(time_value[N]);
    int t = T - 1;
    int max_val = val_acum + dp[N-1][t];

    for (int n = N-1; n >= 1; n--) {
        val_acum += get<1>(time_value[n]);
        t -= get<0>(time_value[n+1]);
        if (t < 0) {
            break;
        } else {
            max_val = max(max_val, val_acum + dp[n-1][t]);
        }
    }

    cout << max_val << "\n";

    return 0;
}

