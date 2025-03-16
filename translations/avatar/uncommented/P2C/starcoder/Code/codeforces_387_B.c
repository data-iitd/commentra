#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, m, i, j ;
    scanf ( "%d %d", &n, &m ) ;
    int round_complexity [ n ], george_complexity [ m ] ;
    for ( i = 0 ; i < n ; i++ )
        scanf ( "%d", &round_complexity [ i ] ) ;
    for ( j = 0 ; j < m ; j++ )
        scanf ( "%d", &george_complexity [ j ] ) ;
    i = j = 0 ;
    while ( i < n && j < m ) {
        i += 1 * ( round_complexity [ i ] <= george_complexity [ j ] ) ;
        j += 1 ;
    }
    printf ( "%d", n - i ) ;
    return 0 ;
}
