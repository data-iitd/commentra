#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool ok(const string& last4) {
    for (int i = 0; i < 4; ++i) {
        string t = last4;
        if (i >= 1) {
            swap(t[i], t[i - 1]);
        }
        if (t.find("AGC") != string::npos) {
            return false;
        }
    }
    return true;
}

int dfs(int cur, const string& last3, vector<unordered_map<string, int>>& memo) {
    if (memo[cur].find(last3) != memo[cur].end()) {
        return memo[cur][last3];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    for (char c : "ACGT") {
        if (ok(last3 + c)) {
            ret = (ret + dfs(cur + 1, last3.substr(1) + c, memo)) % mod;
        }
    }
    memo[cur][last3] = ret;
    return ret;
}

int main() {
    int n;
    cin >> n;
    const int mod = 1000000007;
    vector<unordered_map<string, int>> memo(n + 1);
    cout << dfs(0, "TTT", memo) << endl;
    return 0;
}

