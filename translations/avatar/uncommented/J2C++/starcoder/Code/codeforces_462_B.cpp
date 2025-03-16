#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    char s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 0; i < k; i++) {
        int change = min(s[i] - 'A', k - i);
        ans += change * change;
        s[i] -= change;
        i += change - 1;
    }
    cout << ans << "\n";
    return 0;
}
