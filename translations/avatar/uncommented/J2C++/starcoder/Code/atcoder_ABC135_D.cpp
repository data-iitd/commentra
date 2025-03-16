#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        long long dp[n][13];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 13; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        int base = 1;
        for (int i = 0; i < n; i++) {
            if (s[n - 1 - i] == '?') {
                for (int pre = 0; pre < 13; pre++) {
                    for (int next = 0; next < 10; next++) {
                        dp[i][(base * next + pre) % 13] += (i > 0? dp[i - 1][pre] : (pre == 0? 1 : 0));
                        dp[i][(base * next + pre) % 13] %= 1000000007;
                    }
                }
            } else {
                int next = s[n - 1 - i] - '0';
                for (int pre = 0; pre < 13; pre++) {
                    dp[i][(base * next + pre) % 13] += (i > 0? dp[i - 1][pre] : (pre == 0? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= 1000000007;
                }
            }
            base = base * 10 % 13;
        }
        cout << dp[n - 1][5] << "\n";
    }
    return 0;
}

