#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 0;
    for (auto c : s) {
        ans += c == s[0];
    }
    cout << ans << endl;

    return 0;
}

