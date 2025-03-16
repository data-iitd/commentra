#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, m, i, mx, ind;
    scanf ( "%d %d", &n, &m );
    int *l = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i++ )
        scanf ( "%d", l + i );
    int *l2 = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i++ )
        l2 [ i ] = l [ i ] / m;
    mx = l2 [ 0 ];
    for ( i = 1 ; i < n ; i++ )
        if ( l2 [ i ] > mx )
            mx = l2 [ i ];
    for ( i = 0 ; i < n ; i++ )
        if ( l2 [ i ] == mx )
            ind = i;
    printf ( "%d", ind + 1 );
    return 0;
}
