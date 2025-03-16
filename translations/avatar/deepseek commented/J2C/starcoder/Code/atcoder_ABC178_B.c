#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate x^y mod mod using efficient exponentiation by squaring
int modPower ( int x, int y, int mod ) {
    int res = 1 ;
    x %= mod ;
    if ( x == 0 ) return 0 ;
    while ( y > 0 ) {
        if ( y % 2 == 1 ) {
            res = ( res * x ) % mod ;
        }
        y = y >> 1 ;
        x = ( x * x ) % mod ;
    }
    return res ;
}

// Generic pair class to hold two elements of type T1 and T2
typedef struct {
    int first ;
    int second ;
} pair ;

// Main function to read input, calculate the maximum product, and print the result
int main ( ) {
    pair a [ 4 ] ;
    for ( int i = 0 ; i < 4 ; i ++ ) {
        scanf ( "%d", & a [ i ].first ) ;
        scanf ( "%d", & a [ i ].second ) ;
    }
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].first, a [ 3 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].first, a [ 2 ].second, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 0 ].second, a [ 3 ].first, 1000000007 ) ) ;
    printf ( "%d", modPower ( a [ 1 ].second, a [ 2 ].first, 1000000007