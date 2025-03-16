#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int base = 0;
        long long ans = 0;
        map<int, int> dp;
        for (int i = 0; i < n; i++) {
            base = (base - a[i] % m + m) % m;
            dp[base + a[i] % m]++;
            ans += dp[base];
        }
        cout << ans << "\n";
    }
    return 0;
}
