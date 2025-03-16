#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

int main ( int argc, char * argv [ ] )
{
    int n;
    scanf ( "%d", &n );
    int orig [ n + 1 ] [ n + 1 ];
    for ( int i = 1 ; i <= n ; i ++ )
    {
        for ( int j = 1 ; j <= n ; j ++ )
        {
            scanf ( "%d", &orig [ i ] [ j ] );
        }
    }
    int p [ n + 1 ], q [ n + 1 ];
    for ( int i = 1 ; i <= n ; i ++ )
    {
        scanf ( "%d", &p [ i ] );
    }
    for ( int i = 1 ; i <= n ; i ++ )
    {
        scanf ( "%d", &q [ i ] );
    }
    int pn = 0, qn = 0;
    for ( int i = 0 ; i < n + 1 ; i ++ )
    {
        if ( p [ i ] == orig [ i + 1 ] [ 1 ] )
        {
            pn = i;
        }
        if ( q [ i ] == orig [ i + 1 ] [ 1 ] )
        {
            qn = i;
        }
    }
    printf ( "%d", abs ( pn - qn ) );
    return 0;
}
