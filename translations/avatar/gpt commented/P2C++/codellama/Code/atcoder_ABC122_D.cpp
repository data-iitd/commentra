#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Check if the last 4 characters contain the substring 'AGC'
bool ok(string last4) {
    for (int i = 0; i < 4; i++) {
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

// Compute the number of valid sequences of length n
int dfs(int cur, string last3) {
    // Check if the result for the current state is already computed
    if (memo[cur].find(last3) != memo[cur].end()) {
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
    // Define the modulus for the result
    int mod = 1000000007;
    // Initialize the memoization table
    vector<unordered_map<string, int>> memo(n + 1);
    // Start the depth-first search with the initial state
    cout << dfs(0, "TTT") << endl;
    return 0;
}

