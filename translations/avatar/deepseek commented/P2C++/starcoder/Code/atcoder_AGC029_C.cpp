
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<pair<int, int>> dp;
    dp.push_back({A[0], 0});
    for (int i = 1; i < N; i++) {
        if (A[i] <= dp.back().first) {
            dp = cut(dp, A[i]);
        } else {
            dp.push_back({A[i], 0});
        }
        bool is_added = false;
        for (int j = dp.size() - 1; j >= 0; j--) {
            if (dp[j].second < K - 1) {
                dp = cut(dp, dp[j].first - 1) + {dp[j].first, dp[j].second + 1};
                if (dp.back().first < A[i]) {
                    dp.push_back({A[i], 0});
                }
                is_added = true;
                break;
            }
        }
        if (!is_added) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

