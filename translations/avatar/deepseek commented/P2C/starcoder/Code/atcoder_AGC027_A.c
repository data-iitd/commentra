
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n, x, ans = 0 ;
    scanf ( "%d%d", &n, &x ) ;
    int *a = ( int * ) malloc ( n * sizeof ( int ) ) ;
    for ( int i = 0 ; i < n ; i ++ )
        scanf ( "%d", a + i ) ;
    qsort ( a, n, sizeof ( int ), ( int * ) ( * ( int * ) ( & ( ) ) ) ) ;
    if ( a [ 0 ] > x ) {
        printf ( "0\n" ) ;
        return 0 ;
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] > x ) {
            x = 0 ;
            break ;
        }
        x -= a [ i ] ;
        ans ++ ;
    }
    if ( x!= 0 )
        ans -- ;
    printf ( "%d\n", ans ) ;
    return 0 ;
}

