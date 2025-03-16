
#include <iostream> 
#include <string> 
#include <map> 
#include <vector> 

using namespace std; 

// Number of characters to generate
int N; 
// Modulus value for large number calculations
long MOD = 1000000007L; 
// Possible tokens (characters) to use
string TOKENS[] = { "A", "C", "G", "T" }; 
// Memoization array to store computed results
map<string, long> memo[100000]; 

// Constructor to initialize the class
Main() { 
    // Create a scanner to read input
    cin >> N; 
    // Close the scanner
    cin.close(); 
    // Initialize the memoization array
    for (int i = 0; i < 100000; ++i) { 
        // Initialize each entry in the memoization array with a new HashMap
        memo[i] = map<string, long>(); 
    } 
} 

// Method to calculate the total valid sequences
long calc() { 
    // Start the depth-first search with the initial state
    return dfs(0, "TTT"); 
} 

// Method to check if the last 4 characters are valid
bool isOK(string last4) { 
    // Check if the last 4 characters contain "AGC"
    if (last4.find("AGC") != string::npos) { 
        return false; 
    } 
    // Check all permutations of the last 4 characters
    for (int i = 0; i < 3; ++i) { 
        string vals = last4; 
        // Swap characters to create a new permutation
        vals[i] = last4[i + 1]; 
        vals[i + 1] = last4[i]; 
        string s = vals; 
        // Check if the new permutation contains "AGC"
        if (s.find("AGC") != string::npos) { 
            return false; 
        } 
    } 
    // If no invalid sequences found, return true
    return true; 
} 

// Depth-first search method to explore all possible sequences
long dfs(int current, string last3) { 
    // Check if the result is already computed and stored in memo
    if (memo[current].find(last3) != memo[current].end()) { 
        return memo[current][last3]; 
    } 
    // Base case: if the current length equals N, return 1 (valid sequence)
    if (current == N) { 
        return 1; 
    } 
    // Variable to accumulate the result
    long result = 0; 
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

