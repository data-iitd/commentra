#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
int main ( ) {
    ios_base::sync_with_stdio ( false );
    cin.tie ( 0 );
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> dp(n, vector<ll>(13, 0));
    dp[0][s[0]-'0']++;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 13; k++) {
                dp[i][(k*10+j)%13] += dp[i-1][k];
            }
        }
        if (s[i]!= '?') {
            dp[i][s[i]-'0']++;
        }
    }
    cout << dp[n-1][5] << "\n";
    return 0;
}
