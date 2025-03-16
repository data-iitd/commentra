
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Number of characters to generate
int N;
// Modulus value for large number calculations
long long MOD = 1000000007LL;
// Possible tokens (characters) to use
string TOKENS[] = { "A", "C", "G", "T" };
// Memoization array to store computed results
map<string, long long> memo[1001];

// Method to calculate the total valid sequences
long long calc() {
    // Start the depth-first search with the initial state
    return dfs(0, "TTT");
}

// Method to check if the last 4 characters are valid
bool isOK(string last4) {
    // Check if the last 4 characters contain "AGC"
    if (last4.find("AGC")!= string::npos) {
        return false;
    }
    // Check all permutations of the last 4 characters
    for (int i = 0; i < 3; ++i) {
        string vals = last4;
        // Swap characters to create a new permutation
        swap(vals[i], vals[i + 1]);
        if (vals.find("AGC")!= string::npos) {
            return false;
        }
    }
    // If no invalid sequences found, return true
    return true;
}

// Depth-first search method to explore all possible sequences
long long dfs(int current, string last3) {
    // Check if the result is already computed and stored in memo
    if (memo[current].find(last3)!= memo[current].end()) {
        return memo[current][last3];
    }
    // Base case: if the current length equals N, return 1 (valid sequence)
    if (current == N) {
        return 1;
    }
    // Variable to accumulate the result
    long long result = 0;
    // Iterate through each possible token
    for (string c : TOKENS) {
        // Check if adding the token to the last 3 characters is valid
        if (isOK(last3 + c)) {
            // Recursively call dfs for the next character
            result = (result + dfs(current + 1, last3.substr(1, last3.length()) + c)) % MOD;
        }
    }
    // Store the computed result in memoization array
    memo[current][last3] = result;
    return result;
}

// Main method to execute the program
int main() {
    // Create an instance of Main class
    Main ins;
    // Print the result of the calculation
    cout << ins.calc() << endl;
    return 0;
}
