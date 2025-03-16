#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, m, count [ 100 ] [ 100 ], ans = - 1 ;
    scanf ( "%d%d", &n, &m ) ;
    for ( int i = 0 ; i < n ; i ++ )
        for ( int j = 0 ; j < n ; j ++ )
            count [ i ] [ j ] = 0 ;
    for ( int k = 0 ; k < m ; k ++ ) {
        int x, y ;
        scanf ( "%d%d", &x, &y ) ;
        x -- ;
        y -- ;
        for ( int i = x - 2 ; i <= x + 1 ; i ++ )
            for ( int j = y - 2 ; j <= y + 1 ; j ++ )
                if ( i >= 0 && i < n && j >= 0 && j < n )
                    count [ i ] [ j ] ++ ;
        for ( int i = 0 ; i < n ; i ++ )
            for ( int j = 0 ; j < n ; j ++ )
                if ( count [ i ] [ j ] == 9 ) {
                    ans = k + 1 ;
                    break ;
                }
        if ( ans!= - 1 )
            break ;
    }
    printf ( "%d", ans ) ;
}
