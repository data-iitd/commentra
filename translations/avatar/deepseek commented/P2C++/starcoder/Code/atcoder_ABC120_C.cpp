#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    map<char, int> m;
    for (auto c : s) {
        m[c]++;
    }

    int ans = 0;
    for (auto it : m) {
        ans += min(it.second, 2);
    }

    cout << ans << endl;

    return 0;
}

