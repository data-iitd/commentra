#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Check if the last4 string contains "AGC" more than once
bool ok(string last4) {
    for (int i = 0; i < 4; i++) {
        string t = last4;
        if (i >= 1) {
            // Swap the current and previous character
            swap(t[i], t[i - 1]);
        }
        if (t.find("AGC") != string::npos) {
            // If "AGC" is found, return False
            return false;
        }
    }
    return true;
}

// Recursively call dfs with the next character
int dfs(int cur, string last3) {
    // Check if the result for the current state (cur, last3) is already computed
    if (memo[cur].find(last3) != memo[cur].end()) {
        return memo[cur][last3];
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
            ret = (ret + dfs(cur + 1, last3.substr(1) + c)) % mod;
        }
    }
    memo[cur][last3] = ret;
    return ret;
}

int main() {
    // Read the input value for n
    int n;
    cin >> n;
    int mod = 1000000007;
    // Initialize the memo dictionary for storing computed results
    vector<unordered_map<string, int>> memo(n + 1);
    // Print the result of the dfs function starting with last3 as "TTT"
    cout << dfs(0, "TTT") << endl;
    return 0;
}

