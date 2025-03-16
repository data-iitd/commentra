
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n;
    scanf ( "%d", & n ) ;
    int * l = ( int * ) malloc ( n * sizeof ( int ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", & l [ i ] ) ;
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( i!= j && l [ i ] + 1 == l [ j ] && l [ i ] + 2 == l [ j ] ) {
                printf ( "YES\n" ) ;
                return 0 ;
            }
        }
    }
    printf ( "NO\n" ) ;
    return 0 ;
}
