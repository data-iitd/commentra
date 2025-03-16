#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Define a constant for the modulo operation
    const int M = 1000000007;
    
    // Read a line of input
    string s;
    getline(cin, s);
    
    // Get the length of the input string
    int n = s.length();
    
    // Initialize a 2D vector for dynamic programming
    // dp[i][0] will store the count of valid sequences ending with '0'
    // dp[i][1] will store the count of valid sequences ending with '1'
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    
    // Base case: There is one way to have an empty sequence
    dp[0][0] = 1;
    
    // Iterate through each character in the input string
    for (int i = 0; i < n; i++) {
        // If the current character is '0'
        if (s[i] == '0') {
            // Carry forward the counts for sequences ending with '0' and '1'
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
        } else {
            // If the current character is '1', calculate new counts
            // The count of sequences ending with '1' can be formed by adding
            // the counts of sequences ending with '0' and '1' from the previous step
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M;
        }
        
        // If the current character is '0', update the counts for sequences ending with '1'
        if (s[i] == '0') {
            // Count sequences ending with '1' that can be formed by doubling the previous count
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % M) % M;
        } else {
            // If the current character is '1', update counts for both endings
            // Count sequences ending with '0' that can be formed by doubling the previous count
            dp[i + 1][0] = (dp[i + 1][0] + (dp[i][0] * 2) % M) % M;
            
            // Count sequences ending with '1' that can be formed by doubling the previous count
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % M) % M;
        }
    }
    
    // Output the total number of valid sequences, which is the sum of counts
    // of sequences ending with '0' and '1' for the entire input
    cout << (dp[n][0] + dp[n][1]) % M << endl;

    return 0;
}
// <END-OF-CODE>
