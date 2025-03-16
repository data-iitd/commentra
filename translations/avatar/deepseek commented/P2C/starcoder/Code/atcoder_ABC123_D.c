
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    int x, y, z, k, i, j, a [ 100 ], b [ 100 ], c [ 100 ], ab [ 100 ], abc [ 100 ] ;
    scanf ( "%d%d%d%d", &x, &y, &z, &k ) ;
    for ( i = 0 ; i < x ; i ++ )
        scanf ( "%d", &a [ i ] ) ;
    for ( i = 0 ; i < y ; i ++ )
        scanf ( "%d", &b [ i ] ) ;
    for ( i = 0 ; i < z ; i ++ )
        scanf ( "%d", &c [ i ] ) ;
    for ( i = 0 ; i < x ; i ++ )
        for ( j = 0 ; j < y ; j ++ )
            ab [ i * y + j ] = a [ i ] + b [ j ] ;
    qsort ( ab, x * y, sizeof ( int ), ( int * ) ( * ( ab + 1 ) ) - ( int * ) ( * ab ) ) ;
    for ( i = 0 ; i < k ; i ++ )
        abc [ i ] = ab [ i ] ;
    for ( i = 0 ; i < k ; i ++ )
        for ( j = 0 ; j < z ; j ++ )
            abc [ i ] += c [ j ] ;
    qsort ( abc, k, sizeof ( int ), ( int * ) ( * ( abc + 1 ) ) - ( int * ) ( * abc ) ) ;
    for ( i = 0 ; i < k ; i ++ )
        printf ( "%d\n", abc [ i ] ) ;
    return 0 ;
}

