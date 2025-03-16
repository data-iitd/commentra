

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, x, a [ 100000 ], i, ans = 0 ;
    scanf ( "%d %d", &n, &x ) ;
    for ( i = 0 ; i < n ; i ++ ) scanf ( "%d", &a [ i ] ) ;
    if ( a [ 0 ] > x ) {
        printf ( "0" ) ;
        return 0 ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] > x ) {
            x = 0 ;
            break ;
        }
        x -= a [ i ] ;
        ans ++ ;
    }
    if ( x!= 0 ) ans -- ;
    printf ( "%d", ans ) ;
    return 0 ;
}
// Translate the above Python code to C and end with comment "