#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int ans = 0;
    for (auto c : s) {
        ans += c - 'a';
    }
    cout << ans << '\n';
}

