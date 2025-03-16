

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, m ; scanf ( "%d %d", & n, & m ) ;
    int * lst = ( int * ) malloc ( n * sizeof ( int ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d", lst + i ) ;
    int * l = ( int * ) malloc ( m * sizeof ( int ) ) ;
    for ( int i = 0 ; i < m ; i ++ ) l [ i ] = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) l [ lst [ i ] - 1 ] ++ ;
    int res = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( l [ lst [ i ] - 1 ] > 1 ) {
            res += n - i - l [ lst [ i ] - 1 ] ;
            l [ lst [ i ] - 1 ] -- ;
        } else {
            res += n - i - 1 ;
        }
    }
    printf ( "%d", res ) ;
    free ( lst ) ;
    free ( l ) ;
    return 0 ;
}
// END-OF-CODE