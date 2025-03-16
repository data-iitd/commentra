#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n , m , i , j , k , l , res = 0;
    scanf ( "%d%d" , &n , &m );
    int *lst = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &lst [ i ] );
    }
    int *l = ( int * ) malloc ( m * sizeof ( int ) );
    for ( i = 0 ; i < m ; i ++ ) {
        l [ i ] = 0;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( l [ lst [ i ] ] == 0 ) {
            l [ lst [ i ] ] = 1;
        } else {
            l [ lst [ i ] ] ++;
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( l [ lst [ i ] ] > 1 ) {
            res += n - i - l [ lst [ i ] ];
            l [ lst [ i ] ] --;
        } else {
            res += n - i - 1;
        }
    }
    printf ( "%d" , res );
    return 0;
}
