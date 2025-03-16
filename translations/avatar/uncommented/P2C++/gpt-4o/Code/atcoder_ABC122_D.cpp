#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int n;
unordered_map<string, long long> memo[100005];

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

long long dfs(int cur, const string& last3) {
    if (memo[cur].count(last3)) {
        return memo[cur][last3];
    }
    if (cur == n) {
        return 1;
    }
    long long ret = 0;
    for (char c : "ACGT") {
        if (ok(last3 + c)) {
            ret = (ret + dfs(cur + 1, last3.substr(1) + c)) % MOD;
        }
    }
    memo[cur][last3] = ret;
    return ret;
}

int main() {
    cin >> n;
    cout << dfs(0, "TTT") << endl;
    return 0;
}

// <END-OF-CODE>
