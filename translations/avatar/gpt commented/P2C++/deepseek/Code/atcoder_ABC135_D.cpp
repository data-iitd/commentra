#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    if (n == 1) {
        if (S == "5" || S == "?") {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(13, 0));

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (S[i] != '?') {
                dp[i][stoi(S[i])] += 1;
            } else {
                for (int j = 0; j < 10; ++j) {
                    dp[i][j] += 1;
                }
            }
        } else {
            if (S[i] != '?') {
                for (int k = 0; k < 13; ++k) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];
                }
            } else {
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < 13; ++k) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }
            for (int k = 0; k < 13; ++k) {
                dp[i][k] %= MOD;
            }
        }
    }

    cout << dp[n - 1][5] << '\n';

    return 0;
}
