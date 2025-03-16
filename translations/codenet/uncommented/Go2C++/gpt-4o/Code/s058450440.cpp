#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> a;
int ans = 0;

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
    int n;
    cin >> n;
    unordered_map<char, int> dic;

    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        char ch = c[0];
        if (ch == 'M' || ch == 'A' || ch == 'R' || ch == 'C' || ch == 'H') {
            dic[ch]++;
        }
    }

    for (const auto& v : dic) {
        a.push_back(v.second);
    }

    dfs(3, 0, 1);
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
