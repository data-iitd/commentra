#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to check if the last 4 nucleotides contain the sequence "AGC"
bool ok(const string& last4) {
    // Iterate through the last 4 nucleotides in reverse order
    for (int i = 0; i < 4; ++i) {
        // Create a copy of the last4 string
        string t = last4;
        // Swap the positions of the current and previous nucleotides
        if (i >= 1) {
            swap(t[i], t[i - 1]);
        }
        
        // Check if the swapped sequence contains "AGC"
        if (t.find("AGC") != string::npos) {
            // If yes, return false
            return false;
        }
    }
    // If no "AGC" sequence is found, return true
    return true;
}

// Function to perform Depth-First Search (DFS) to find the number of valid sequences
int dfs(int cur, const string& last3, vector<unordered_map<string, int>>& memo, int n, int mod) {
    // Check if the subproblem has already been solved
    if (memo[cur].find(last3) != memo[cur].end()) {
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
            ret = (ret + dfs(cur + 1, last3.substr(1) + c, memo, n, mod)) % mod;
        }
    }
    
    // Store the result in the memoization table and return it
    memo[cur][last3] = ret;
    return ret;
}

int main() {
    // Read the input: the number of nucleotides (n)
    int n;
    cin >> n;

    // Initialize the memoization table with empty maps
    vector<unordered_map<string, int>> memo(n + 1);

    // Initialize the modulus value
    int mod = 1e9 + 7;

    // Perform DFS and print the result
    cout << dfs(0, "TTT", memo, n, mod) << endl;

    return 0;
}

// <END-OF-CODE>
