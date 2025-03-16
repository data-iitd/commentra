#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main ( ) {
    int n, k ;
    scanf ( "%d %d", & n, & k ) ;
    char * v = ( char * ) malloc ( n + 1 ) ;
    scanf ( "%s", v ) ;
    bool f = k - 1 < n - k ;
    int m = f? k - 1 : n - k ;
    char * a = ( char * ) malloc ( m * 2 * sizeof ( char ) ) ;
    for ( int i = 0 ; i < m ; i ++ ) {
        a [ 2 * i ] = f? "RIGHT" : "LEFT" ;
        a [ 2 * i + 1 ] = f? "LEFT" : "RIGHT" ;
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( i < m ) {
            a [ 2 * i + 2 * m ] = "PRINT " ;
            strcat ( a + 2 * i + 2 * m + 6, v + i ) ;
        }
        if ( i < m - 1 ) {
            a [ 2 * i + 1 + 2 * m ] = f? "RIGHT" : "LEFT" ;
        }
    }
    printf ( "%s\n", a ) ;
    return 0 ;
}
