
#include <bits/stdc++.h>
using namespace std;

int n, ans;
map<char, int> mp;
vector<int> a;

void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < a.size(); j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s[0]]++;
    }
    for (auto it : mp) {
        if (it.first == 'M' || it.first == 'A' || it.first == 'R' || it.first == 'C' || it.first == 'H') {
            a.push_back(it.second);
        }
    }
    dfs(3, 0, 1);
    cout << ans << endl;
    return 0;
}

