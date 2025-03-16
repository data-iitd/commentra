
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, int> dic;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        switch (c) {
        case 'M':
        case 'A':
        case 'R':
        case 'C':
        case 'H':
            dic[c]++;
            break;
        }
    }
    vector<int> a;
    for (auto &[c, v] : dic) {
        a.push_back(v);
    }
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.size(); j++) {
            dfs(left - 1, j + 1, res * a[j]);
        }
    };
    dfs(3, 0, 1);
    cout << ans << endl;
    return 0;
}

