#include <stdio.h>
#include <stdlib.h>
int main ( ) {
    int n, a [ 100001 ], b [ 100001 ], c = 0, par [ 100001 ], rank [ 100001 ], size [ 100001 ] ;
    scanf ( "%d", & n ) ;
    for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d", & a [ i ] ) ;
    for ( int i = 0 ; i < n ; i ++ ) b [ a [ i ] - 1 ] = i ;
    for ( int i = 0 ; i < n ; i ++ ) par [ i ] = i, rank [ i ] = 1, size [ i ] = 1 ;
    for ( int k = n - 1 ; k >= 0 ; k -- ) {
        int l = 1, r = 1 ;
        if ( k > 0 && a [ k - 1 ] > a [ k ] ) {
            l += size [ par [ k - 1 ] ] ;
            unite ( k - 1, k ) ;
        }
        if ( k + 1 < n && a [ k + 1 ] > a [ k ] ) {
            r += size [ par [ k + 1 ] ] ;
            unite ( k + 1, k ) ;
        }
        c += l * r * a [ k ] ;
    }
    printf ( "%d", c ) ;
    return 0 ;
}
