
#include <bits/stdc++.h>
using namespace std;

int n, ans;
map<char, int> mp;

void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < n; j++) {
        dfs(left - 1, j + 1, res * mp[j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            mp[c]++;
        }
    }

    vector<int> a;
    for (auto &[key, value] : mp) {
        a.push_back(value);
    }

    dfs(3, 0, 1);
    cout << ans << endl;

    return 0;
}

