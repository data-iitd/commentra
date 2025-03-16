
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int x, y, z, k;
    scanf ( "%d %d %d %d", &x, &y, &z, &k );
    int *a = ( int * ) malloc ( sizeof ( int ) * x );
    int *b = ( int * ) malloc ( sizeof ( int ) * y );
    int *c = ( int * ) malloc ( sizeof ( int ) * z );
    for ( int i = 0; i < x; i ++ ) scanf ( "%d", &a [ i ] );
    for ( int i = 0; i < y; i ++ ) scanf ( "%d", &b [ i ] );
    for ( int i = 0; i < z; i ++ ) scanf ( "%d", &c [ i ] );
    int *ab = ( int * ) malloc ( sizeof ( int ) * x * y );
    for ( int i = 0; i < x; i ++ ) {
        for ( int j = 0; j < y; j ++ ) {
            ab [ i * y + j ] = a [ i ] + b [ j ];
        }
    }
    qsort ( ab, x * y, sizeof ( int ), cmpfunc );
    int *abc = ( int * ) malloc ( sizeof ( int ) * x * y * z );
    for ( int i = 0; i < x * y; i ++ ) {
        for ( int j = 0; j < z; j ++ ) {
            abc [ i * z + j ] = ab [ i ] + c [ j ];
        }
    }
    qsort ( abc, x * y * z, sizeof ( int ), cmpfunc );
    for ( int i = 0; i < k; i ++ ) {
        printf ( "%d\n", abc [ x * y * z - 1 - i ] );
    }
    free ( a );
    free ( b );
    free ( c );
    free ( ab );
    free ( abc );
    return 0;
}

int cmpfunc ( const void * a, const void * b ) {
    return ( *( int * ) a ) - ( *( int * ) b );
}

