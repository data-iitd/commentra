
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, mod = 1e9 + 7;
int dp[N][13];
int main () {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        if (s[0] == '5' || s[0] == '?') cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '?') {
                for (int j = 0; j < 10; j++) dp[i][j]++;
            }
            else dp[i][s[i] - '0']++;
        }
        else {
            if (s[i] == '?') {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        dp[i][(k * 10 + j) % 13] %= mod;
                    }
                }
            }
            else {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + s[i] - '0') % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + s[i] - '0') % 13] %= mod;
                }
            }
        }
    }
    cout << dp[n - 1][5] << endl;
    return 0;
}
