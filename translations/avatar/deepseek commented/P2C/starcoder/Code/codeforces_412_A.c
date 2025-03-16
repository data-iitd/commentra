
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, k ;
    scanf ( "%d %d", & n, & k ) ;
    char * v = ( char * ) malloc ( n + 1 ) ;
    scanf ( "%s", v ) ;
    char * d [ ] = { "LEFT", "RIGHT" } ;
    int f = k - 1 < n - k ;
    int m = min ( k - 1, n - k ) ;
    char * a [ m * 2 + 1 ] ;
    for ( int i = 0 ; i < m ; i ++ ) {
        a [ i ] = d [! f ] ;
    }
    for ( int i = 0 ; i < m * 2 ; i += 2 ) {
        a [ i ] = "PRINT" ;
        a [ i + 1 ] = d [ f ] ;
    }
    for ( int i = 0 ; i < n ; i += 2 * f - 1 ) {
        a [ m * 2 + i / 2 ] = v [ i ] ;
    }
    for ( int i = 0 ; i < m * 2 + n / 2 ; i ++ ) {
        printf ( "%s\n", a [ i ] ) ;
    }
    return 0 ;
}

