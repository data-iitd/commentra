#include <math.h>
#include <stdio.h>
int main ( ) {
    int N;
    scanf ( "%d", &N );
    double XY [ 2 * N ], X, Y, D [ 2 * N ], ans = 0;
    for ( int i = 0 ; i < 2 * N ; i ++ )
        scanf ( "%lf%lf", &XY [ i ], &XY [ i + 1 ] );
    for ( int i = 0 ; i < 2 * N ; i ++ ) {
        D [ i ] = atan2 ( XY [ i ] - XY [ i + 2 * N ], XY [ i + 1 ] - XY [ i + 2 * N + 1 ] );
        D [ i + 2 * N ] = D [ i ] + 2 * M_PI;
    }
    for ( int i = 0 ; i < 2 * N ; i ++ ) {
        for ( int j = i + 1 ; j < 2 * N ; j ++ ) {
            if ( D [ j ] - D [ i ] >= M_PI )
                ans += ( D [ j ] - D [ i ] ) - M_PI;
        }
    }
    printf ( "%.10lf\n", ans / ( 2 * M_PI ) );
    return 0;
}
