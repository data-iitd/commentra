
#include <iostream>
#include <string>
#include <map>
using namespace std;

// This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
// It returns False if it does, and True otherwise.
// Input: last4 (a list of 4 nucleotides)
// Output: A boolean value
bool ok(string last4) {
    // Iterate through the last 4 nucleotides in reverse order
    for (int i = 3; i >= 0; i--) {
        // Swap the positions of the current and previous nucleotides
        string t = last4;
        if (i >= 1) {
            t[i] = last4[i-1];
            t[i-1] = last4[i];
        }
        
        // Check if the swapped sequence contains "AGC"
        if (t.find("AGC") != string::npos) {
            // If yes, return False and exit the function
            return false;
        }
    }
    
    // If no "AGC" sequence is found, return True
    return true;
}

// This function performs Depth-First Search (DFS) to find the number of valid sequences
// Input: cur (the current index), last3 (the last 3 nucleotides)
// Output: An integer value representing the number of valid sequences
int dfs(int cur, string last3) {
    // Memoization table to store the results of subproblems
    static map<string, int> memo[100001];
    
    // Base case: If we have reached the end of the sequence, return 1
    if (cur == n) {
        return 1;
    }
    
    // Initialize the result to 0
    int ret = 0;
    
    // Iterate through all possible nucleotides (A, C, G, T)
    for (char c = 'A'; c <= 'T'; c++) {
        // Check if the next nucleotide can be added to the last 3 nucleotides
        if (ok(last3 + c)) {
            // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
            ret = (ret + dfs(cur+1, last3.substr(1) + c)) % mod;
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
    
    // Initialize the modulus value
    int mod = 1000000007;
    
    // Perform DFS and print the result
    cout << dfs(0, "TTT") << endl;
    
    return 0;
}

