
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 1000000
#define K 1000000
#define MOD 1000000007
char S [ N + 10 ];
int main ( ) {
    int N, K, i, j, count, a, b, c, d, e, f, g, h, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, a, b, c, d, e, f, g, h, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z ;
    scanf ( "%d%d", &N, &K );
    scanf ( "%s", S );
    if ( K >= 15 ) {
        printf ( "%c", S [ 0 ] );
        for ( i = 1 ; i < N ; i ++ )
            printf ( "%c", S [ 0 ] );
        printf ( "\n" );
        return 0;
    }
    if ( 2 * ( 1 << K ) >= N ) {
        printf ( "%c", S [ 0 ] );
        for ( i = 1 ; i < N ; i ++ )
            printf ( "%c", S [ 0 ] );
        printf ( "\n" );
        return 0;
    }
    if ( K == 1 ) {
        printf ( "%s\n", S );
        return 0;
    }
    count = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        if ( S [ i ] == S [ 0 ] )
            count ++;
        else
            break;
    }
    if ( count * ( 1 << ( K - 1 ) ) >= N ) {
        printf ( "%c", S [ 0 ] );
        for ( i = 1 ; i < N ; i ++ )
            printf ( "%c", S [ 0 ] );
        printf ( "\n" );
        return 0;
    }
    for ( i = 0 ; i < count ; i ++ )
        S [ i ] = S [ 0 ];
    for ( i = count ; i < N ; i ++ )
        S [ i ] = S [ i - count ];
    printf ( "%s\n", S );
    return 0;
}

