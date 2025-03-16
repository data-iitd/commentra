

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int n;
map<string, ll> dp[MAXN];
string tokens[4] = {"A", "C", "G", "T"};

bool is_ok(string s) {
    for (int i = 0; i < 3; i++) {
        swap(s[i], s[i + 1]);
        if (s.substr(i, 3) == "AGC") return false;
        swap(s[i], s[i + 1]);
    }
    return true;
}

ll dfs(int idx, string last3) {
    if (idx == n) return 1;
    if (dp[idx].count(last3)) return dp[idx][last3];
    ll res = 0;
    for (auto c : tokens) {
        string nxt = last3.substr(1) + c;
        if (is_ok(nxt)) {
            res = (res + dfs(idx + 1, nxt)) % MOD;
        }
    }
    return dp[idx][last3] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cout << dfs(0, "TTT") << endl;
    return 0;
}

