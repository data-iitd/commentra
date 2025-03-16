#include <bits/stdc++.h>
using namespace std;

// Define a constant for the modulo operation
const long long MOD = 998244353; 

// Create a 2D array for dynamic programming
long long dp[3001][3001]; 

// Method to solve the problem
void solve(int A, int B, int C, int D) {
    // Initialize the starting point in the dp array
    dp[A][B] = 1; 
    
    // Iterate over the range from A to C and B to D
    for (int c = A; c <= C; c++) { 
        for (int d = B; d <= D; d++) { 
            // Skip the initial point
            if (c == A && d == B) { 
                continue; 
            } 
            
            // Variable to store the current answer
            long long ans = 0; 
            
            // If moving down (increasing c)
            if (c > A) { 
                long long part = dp[c - 1][d]; 
                ans = (part * d); // Calculate contribution from the previous row
            } 
            
            // If moving right (increasing d)
            if (d > B) { 
                long long part = dp[c][d - 1]; 
                ans = (ans + (part * c)); // Calculate contribution from the previous column
            } 
            
            // If moving diagonally (increasing both c and d)
            if (c > A && d > B) { 
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); // Adjust for double counting
            } 
            
            // Store the result in the dp array with modulo adjustment
            dp[c][d] = ((ans % MOD) + MOD) % MOD; 
        } 
    } 
} 

// Main method to execute the program
int main() { 
    int A, B, C, D; // Initialize variables for input
    cin >> A >> B >> C >> D; // Read input values A, B, C, D from the scanner
    solve(A, B, C, D); // Create an instance of Main and call solve method
    return 0;
}

