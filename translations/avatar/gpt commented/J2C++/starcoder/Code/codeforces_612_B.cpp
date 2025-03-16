#include <bits/stdc++.h>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    int n;
    cin >> n;
    int dp[200001];
    for (int i = 0; i < n; i++) {
        cin >> dp[i];
    }
    long ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }
    cout << ans << "\n";
    return 0;
}

