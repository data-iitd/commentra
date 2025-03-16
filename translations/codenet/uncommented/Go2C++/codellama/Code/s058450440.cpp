
#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    for (auto v : dic) {
        a.push_back(v.second);
    }

    int ans = 0;
    dfs(3, 0, 1, a, ans);
    cout << ans << endl;

    return 0;
}

void dfs(int left, int i, int res, vector<int> a, int& ans) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < a.size(); j++) {
        dfs(left - 1, j + 1, res * a[j], a, ans);
    }
}

