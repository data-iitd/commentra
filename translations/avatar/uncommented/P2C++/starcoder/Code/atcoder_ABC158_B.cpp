#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        int ans = 0;
        int rep = n / (a + b);
        ans += rep * a;
        int res = n - rep * (a + b);
        ans += min(res, a);
        cout << ans << "\n";
    }
    return 0;
}
