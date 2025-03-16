#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Main {
    // Number of characters to generate
    int N; 
    // Modulus value for large number calculations
    long long MOD = 1000000007; 
    // Possible tokens (characters) to use
    string TOKENS[4] = { "A", "C", "G", "T" }; 
    // Memoization array to store computed results
    unordered_map<string, long long> memo[100]; 

public:
    // Constructor to initialize the class
    Main() { 
        // Read the number of characters to generate
        cin >> N; 
    } 

    // Method to calculate the total valid sequences
    long long calc() { 
        // Start the depth-first search with the initial state
        return dfs(0, "TTT"); 
    } 

    // Method to check if the last 4 characters are valid
    bool isOK(const string& last4) { 
        // Check if the last 4 characters contain "AGC"
        if (last4.find("AGC") != string::npos) { 
            return false; 
        } 
        // Check all permutations of the last 4 characters
        for (int i = 0; i < 3; ++i) { 
            string s = last4;
            swap(s[i], s[i + 1]); // Swap characters to create a new permutation
            // Check if the new permutation contains "AGC"
            if (s.find("AGC") != string::npos) { 
                return false; 
            } 
        } 
        // If no invalid sequences found, return true
        return true; 
    } 

    // Depth-first search method to explore all possible sequences
    long long dfs(int current, const string& last3) { 
        // Check if the result is already computed and stored in memo
        if (memo[current].find(last3) != memo[current].end()) { 
            return memo[current][last3]; 
        } 
        // Base case: if the current length equals N, return 1 (valid sequence)
        if (current == N) { 
            return 1; 
        } 
        // Variable to accumulate the result
        long long result = 0; 
        // Iterate through each possible token
        for (const string& c : TOKENS) { 
            // Check if adding the token to the last 3 characters is valid
            if (isOK(last3 + c)) { 
                // Recursively call dfs for the next character
                result = (result + dfs(current + 1, last3.substr(1) + c)) % MOD; 
            } 
        } 
        // Store the computed result in memoization array
        memo[current][last3] = result; 
        return result; 
    } 
};

// Main method to execute the program
int main() { 
    // Create an instance of Main class
    Main ins; 
    // Print the result of the calculation
    cout << ins.calc() << endl; 
    return 0; 
}

// <END-OF-CODE>
