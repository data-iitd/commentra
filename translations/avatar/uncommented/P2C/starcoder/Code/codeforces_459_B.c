#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int n, i, j, a, b, ac, bc;
    scanf ( "%d", &n );
    int *l1 = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i++ )
        scanf ( "%d", &l1 [ i ] );
    qsort ( l1, n, sizeof ( int ), cmpfunc );
    a = l1 [ n - 1 ];
    b = l1 [ 0 ];
    ac = 0;
    bc = 0;
    for ( i = 0 ; i < n ; i++ )
    {
        if ( l1 [ i ] == a )
            ac++;
        if ( l1 [ i ] == b )
            bc++;
    }
    if ( a == b )
        printf ( "%d %d", a - b, ac * ( ac - 1 ) / 2 );
    else
        printf ( "%d %d", a - b, ac * bc );
    return 0;
}

int cmpfunc ( const void *a, const void *b )
{
    return ( *( int * ) a - *( int * ) b );
}

