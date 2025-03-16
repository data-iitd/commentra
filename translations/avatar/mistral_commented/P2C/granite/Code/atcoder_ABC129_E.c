
#include <stdio.h>
#include <string.h>

// Modulus constant for fast modular arithmetic
#define mod 100000007

int main () {
    // Read input string length
    char l [ 100001 ];
    scanf ( "%s", l );
    int n = strlen ( l );

    // Initialize 2D dynamic programming table
    long long dp [ n + 1 ] [ 2 ];
    memset ( dp, 0, sizeof ( dp ) );

    // Base case: empty string has 1 solution
    dp [ 0 ] [ 0 ] = 1;

    // Iterate through each character in the input string
    for ( int i = 0; i < n; i ++ ) {
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
    printf ( "%lld\n", ( dp [ n ] [ 0 ] + dp [ n ] [ 1 ] ) % mod );

    return 0;
}
