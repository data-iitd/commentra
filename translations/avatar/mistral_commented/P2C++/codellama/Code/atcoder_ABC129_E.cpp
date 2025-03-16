#include <iostream>
#include <string>

using namespace std;

// Modulus constant for fast modular arithmetic
const int mod = 1000000007;

// Read input string length
int l;
cin >> l;

// Initialize 2D dynamic programming table
int dp [ 100001 ] [ 2 ];

// Base case: empty string has 1 solution
dp [ 0 ] [ 0 ] = 1;

// Iterate through each character in the input string
for ( int i = 0; i < l; i++ ) {
    // Update dp[i+1][0] based on current character '0' or '1'
    if ( l [ i ] == '0' ) {
        dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ];
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
    } else {
        dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ] * 2;
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 0 ];
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
    }

    // Perform modular arithmetic to keep the values within the modulus
    dp [ i + 1 ] [ 0 ] %= mod;
    dp [ i + 1 ] [ 1 ] %= mod;
}

// Calculate the final answer
cout << ( dp [ l ] [ 0 ] + dp [ l ] [ 1 ] ) % mod << endl;

