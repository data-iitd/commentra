#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main ( ) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>(13, 0));
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i]!= '?') {
                dp[i][s[i] - '0']++;
            } else {
                for (int j = 0; j < 10; j++) {
                    dp[i][j]++;
                }
            }
        } else {
            if (s[i]!= '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + s[i] - '0') % 13] += dp[i - 1][k];
                }
            } else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }
            for (int k = 0; k < 13; k++) {
                dp[i][k] %= mod;
            }
        }
    }
    cout << dp[n - 1][5];
    return 0;
}

