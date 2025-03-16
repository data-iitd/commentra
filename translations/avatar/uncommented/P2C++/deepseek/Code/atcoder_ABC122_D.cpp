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

int dfs(int cur, const string& last3, unordered_map<string, int>& memo, int mod) {
    if (memo.find(last3) != memo.end()) {
        return memo[last3];
    }
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    for (char c : "ACGT") {
        if (ok(last3 + c)) {
            ret = (ret + dfs(cur + 1, last3.substr(1) + c, memo, mod)) % mod;
        }
    }
    memo[last3] = ret;
    return ret;
}

int main() {
    int n;
    cin >> n;
    int mod = 1000000007;
    unordered_map<string, int> memo[n + 1];
    cout << dfs(0, "TTT", memo[0], mod) << endl;
    return 0;
}

