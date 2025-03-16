
#include <stdio.h>

int main ( void ) {
    int n, m, r, c, i, sum = 0 ;
    scanf ( "%d %d", &n, &m ) ;
    int b [ n * 2 ] ;
    for ( i = 0 ; i < n * 2 ; i ++ ) b [ i ] = 1 ;
    b [ 0 ] = b [ n - 1 ] = b [ n ] = b [ 2 * n - 1 ] = 0 ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d %d", &r, &c ) ;
        b [ r - 1 ] = b [ n + c - 1 ] = 0 ;
    }
    if ( n % 2 && b [ n / 2 ] && b [ n + n / 2 ] ) b [ n / 2 ] = 0 ;
    for ( i = 0 ; i < n * 2 ; i ++ ) sum += b [ i ] ;
    printf ( "%d", sum ) ;
    return 0 ;
}
