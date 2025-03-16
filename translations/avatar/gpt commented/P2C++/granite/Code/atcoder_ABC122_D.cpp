
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool ok(string last4) {
    // Check if the last 4 characters contain the substring 'AGC'
    for (int i = 0; i < 4; i++) {
        // Create a vector from the last4 string to allow swapping
        vector<char> t(last4.begin(), last4.end());
        // Swap the current character with the previous one if not the first character
        if (i >= 1) {
            swap(t[i], t[i - 1]);
        }
        // If 'AGC' is found in the modified string, return false
        if (count(t.begin(), t.end(), 'A') + count(t.begin(), t.end(), 'G') + count(t.begin(), t.end(), 'C') >= 1) {
            return false;
        }
    }
    // If 'AGC' is not found in any of the permutations, return true
    return true;
}

int dfs(int cur, string last3) {
    // Check if the result for the current state is already computed
    if (memo.count(cur) && memo[cur].count(last3)) {
        return memo[cur][last3];
    }
    // If we have reached the end of the sequence, return 1 (valid sequence found)
    if (cur == n) {
        return 1;
    }
    int ret = 0;
    // Iterate through each possible character 'A', 'C', 'G', 'T'
    for (char c : "ACGT") {
        // Check if adding the current character keeps the sequence valid
        if (ok(last3 + c)) {
            // Recursively call dfs for the next position with the updated last3
            ret = (ret + dfs(cur + 1, last3.substr(1) + c)) % mod;
        }
    }
    // Store the computed result in the memoization table
    memo[cur][last3] = ret;
    return ret;
}

int main() {
    // Read the length of the sequence from input
    int n;
    cin >> n;
    // Initialize the memoization table
    unordered_map<int, unordered_map<string, int>> memo;
    // Start the depth-first search with the initial state
    cout << dfs(0, "TTT") << endl;
    return 0;
}

