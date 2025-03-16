#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string l;
    cin >> l;
    int n = l.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        if (l[i] == '0') {
            dp[i + 1][0] += dp[i][0];
            dp[i + 1][1] += dp[i][1] * 3;
        } else {
            dp[i + 1][0] += dp[i][0] * 2;
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][1] += dp[i][1] * 3;
        }
    }

    int result = (dp[n][0] + dp[n][1]) % 1000000007;
    cout << result << "\n";

    return 0;
}

