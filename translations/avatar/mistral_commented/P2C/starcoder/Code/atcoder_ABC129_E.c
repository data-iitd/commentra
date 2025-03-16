#include <stdio.h>
#include <stdlib.h>

// Modulus constant for fast modular arithmetic
#define mod 1000000007

int main ( ) {
    // Read input string length
    int l;
    scanf ( "%d", &l );

    // Initialize 2D dynamic programming table
    int **dp = ( int ** ) malloc ( ( l + 1 ) * sizeof ( int * ) );
    for ( int i = 0; i <= l; i++ ) {
        dp [ i ] = ( int * ) malloc ( 2 * sizeof ( int ) );
        dp [ i ] [ 0 ] = 0;
        dp [ i ] [ 1 ] = 0;
    }

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
    printf ( "%d\n", ( dp [ l ] [ 0 ] + dp [ l ] [ 1 ] ) % mod );

    // Free the memory
    for ( int i = 0; i <= l; i++ ) {
        free ( dp [ i ] );
    }
    free ( dp );

    return 0;
}

