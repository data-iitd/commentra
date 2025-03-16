
#include <bits/stdc++.h>
using namespace std;

// Global variables
int n;
int mod;
map<int, map<string, int>> memo;

// Function to check if the last 4 nucleotides (last4) contain the sequence "AGC" or not
bool ok(vector<char> last4) {
    // Iterate through the last 4 nucleotides in reverse order
    for (int i = 0; i < 4; i++) {
        // Swap the positions of the current and previous nucleotides
        char t = last4[i];
        last4[i] = last4[i-1];
        last4[i-1] = t;
        
        // Check if the swapped sequence contains "AGC"
        if (string(last4).count("AGC") >= 1) {
            // If yes, return False and exit the function
            return false;
        }
    }
    
    // If no "AGC" sequence is found, return True
    return true;
}

// Function to perform Depth-First Search (DFS) to find the number of valid sequences
int dfs(int cur, string last3) {
    // Memoization table to store the results of subproblems
    if (memo[cur].find(last3)!= memo[cur].end()) {
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
    for (char c = 'A'; c <= 'T'; c++) {
        // Check if the next nucleotide can be added to the last 3 nucleotides
        if (ok(vector<char>(last3.begin(), last3.end() + 1))) {
            // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
            ret = (ret + dfs(cur+1, last3.substr(1) + c)) % mod;
        }
    }
    
    // Store the result in the memoization table and return it
    memo[cur][last3] = ret;
    return ret;
}

// Main function
int main() {
    // Read the input: the number of nucleotides (n)
    cin >> n;
    
    // Initialize the memoization table with empty dictionaries
    memo = vector<map<string, int>>(n+1);
    
    // Initialize the modulus value
    mod = 1000000007;
    
    // Perform DFS and print the result
    cout << dfs(0, "TTT") << endl;
    
    return 0;
}

