
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

bool ok(string last4) {
    // Check if the last4 string contains "AGC" more than once
    for (int i = 0; i < 4; i++) {
        string t = last4;
        if (i >= 1) {
            // Swap the current and previous character
            swap(t[i], t[i - 1]);
        }
        if (count(t.begin(), t.end(), 'A') + count(t.begin(), t.end(), 'G') + count(t.begin(), t.end(), 'C') >= 1) {
            // If "AGC" is found, return False
            return false;
        }
    }
    return true;
}

int dfs(int cur, string last3) {
    // Check if the result for the current state (cur, last3) is already computed
    static unordered_map<string, unordered_map<string, int>> memo;
    if (memo.find(to_string(cur))!= memo.end() && memo[to_string(cur)].find(last3)!= memo[to_string(cur)].end()) {
        return memo[to_string(cur)][last3];
    }
    if (cur == n) {
        // Base case: if current length equals n, return 1 (valid sequence)
        return 1;
    }
    int ret = 0;
    for (char c : "ACGT") {
        // Check if adding the character c to last3 forms a valid sequence
        if (ok(last3 + c)) {
            // Recursively call dfs with the next character
            ret = (ret + dfs(cur + 1, last3.substr(1) + c)) % MOD;
        }
    }
    memo[to_string(cur)][last3] = ret;
    return ret;
}

int main() {
    int n;
    cin >> n;
    // Print the result of the dfs function starting with last3 as "TTT"
    cout << dfs(0, "TTT") << endl;
    return 0;
}

