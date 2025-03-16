#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define dprint(x)
#define MOD 998244353
#define N 8000
int g1 [ N + 10 ], g2 [ N + 10 ], inverse [ N + 10 ] ;
int cmb ( int n, int r ) {
    if ( r < 0 || r > n ) return 0 ;
    r = min ( r, n - r ) ;
    return g1 [ n ] * g2 [ r ] * g2 [ n - r ] % MOD ;
}
int kumiawase ( int p, int q ) {
    return cmb ( p + q - 1, q - 1 ) ;
}
int solve ( int n ) {
    assert ( n <= K + 1 ) ;
    int ans = 0, kumi = ( n - 1 ) / 2 ;
    for ( int p = 0 ; p <= kumi ; p ++ ) {
        if ( p > N ) break ;
        ans += 1LL * pow ( 2, p ) * cmb ( kumi, p ) * kumiawase ( N - p, p + ( K - kumi * 2 - ( n & 1 ) ) ) ;
        if ( n & 1 && N - p - 1 >= 0 ) ans += 1LL * pow ( 2, p ) * cmb ( kumi, p ) * kumiawase ( N - p - 1, p + ( K - kumi * 2 - ( n & 1 ) ) ) ;
    }
    return ans ;
}
int main ( ) {
    int T, t = 1 ;
    scanf ( "%d", & T ) ;
    while ( T -- ) {
        scanf ( "%d%d", & K, & N ) ;
        printf ( "Case #%d: ", t ++ ) ;
        printf ( "%d\n", solve ( N ) ) ;
    }
    return 0 ;
}
