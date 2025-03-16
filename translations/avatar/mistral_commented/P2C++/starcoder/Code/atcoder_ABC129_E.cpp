#include <bits/stdc++.h>
using namespace std;

// Modulus constant for fast modular arithmetic
const int mod = 1000000007;

// Function to calculate the number of ways to decode a given string
int countWays ( string &s ) {
    // Initialize 2D dynamic programming table
    int dp [ s.length () + 1 ] [ 2 ];
    dp [ 0 ] [ 0 ] = 1;

    // Iterate through each character in the input string
    for ( int i = 0 ; i < s.length () ; i++ ) {
        // Update dp[i+1][0] based on current character '0' or '1'
        if ( s [ i ] == '0' ) {
            dp [ i + 1 ] [ 0 ] = dp [ i ] [ 0 ] + dp [ i ] [ 1 ];
            dp [ i + 1 ] [ 1 ] = dp [ i ] [ 0 ] * 3;
        }
        else {
            dp [ i + 1 ] [ 0 ] = dp [ i ] [ 0 ] * 2 + dp [ i ] [ 1 ];
            dp [ i + 1 ] [ 1 ] = dp [ i ] [ 0 ] + dp [ i ] [ 1 ] * 3;
        }

        // Perform modular arithmetic to keep the values within the modulus
        dp [ i + 1 ] [ 0 ] %= mod;
        dp [ i + 1 ] [ 1 ] %= mod;
    }

    // Calculate the final answer
    return ( dp [ s.length () ] [ 0 ] + dp [ s.length () ] [ 1 ] ) % mod;
}

// Driver code
int main ( ) {
    // Read input string length
    string s;
    cin >> s;
    int n = s.length ( );

    // Calculate the final answer
    cout << countWays ( s ) << endl;
    return 0;
}

