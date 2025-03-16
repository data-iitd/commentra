#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int n, i, j, k, l, m, t, *a, *b, *c, *d;
    scanf ( "%d", &n );
    a = ( int * ) malloc ( n * sizeof ( int ) );
    b = ( int * ) malloc ( n * sizeof ( int ) );
    c = ( int * ) malloc ( n * sizeof ( int ) );
    d = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i++ )
        scanf ( "%d", &a[i] );
    for ( i = 0 ; i < n ; i++ )
        b[i] = a[i];
    for ( i = 0 ; i < n ; i++ )
        c[i] = a[i];
    for ( i = 0 ; i < n ; i++ )
        d[i] = a[i];
    for ( i = 0 ; i < n ; i++ )
        for ( j = 0 ; j < n ; j++ )
            if ( b[i] == c[j] )
                d[i] = d[i] + 1;
    for ( i = 0 ; i < n ; i++ )
        if ( d[i] == 2 )
            break;
    if ( i == n )
        printf ( "NO" );
    else
        printf ( "YES" );
    return 0;
}
