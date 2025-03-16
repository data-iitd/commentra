#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
// It returns false if it does, and true otherwise.
bool ok(const string& last4) {
    for (int i = 0; i < 4; ++i) {
        // Swap the positions of the current and previous nucleotides
        string t = last4;
        if (i >= 1) {
            swap(t[i], t[i - 1]);
        }
        
        // Check if the swapped sequence contains "AGC"
        if (t.find("AGC") != string::npos) {
            // If yes, return false and exit the function
            return false;
        }
    }
    // If no "AGC" sequence is found, return true
    return true;
}

// This function performs Depth-First Search (DFS) to find the number of valid sequences
// Input: cur (the current index), last3 (the last 3 nucleotides)
// Output: An integer value representing the number of valid sequences
unordered_map<string, int> memo[101];
const int mod = 1000000007;

int dfs(int cur, const string& last3) {
    // Memoization table to store the results of subproblems
    if (memo[cur].find(last3) != memo[cur].end()) {
        // If the subproblem has already been solved, return the stored result
        return memo[cur][last3];
    }
    
    // Base case: If we have reached the end of the sequence, return 1
    if (cur == n) {
        return 1;
    }
    
    // Initialize the result to 0
    int ret = 0;
    
    // Iterate through all possible nucleotides (A, C, G, T)
    for (char c : "ACGT") {
        // Check if the next nucleotide can be added to the last 3 nucleotides
        if (ok(last3 + c)) {
            // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
            ret = (ret + dfs(cur + 1, last3.substr(1) + c)) % mod;
        }
    }
    
    // Store the result in the memoization table and return it
    memo[cur][last3] = ret;
    return ret;
}

int main() {
    // Read the input: the number of nucleotides (n)
    cin >> n;
    
    // Perform DFS and print the result
    cout << dfs(0, "TTT") << endl;
    
    return 0;
}
