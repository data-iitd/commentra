
#include <stdio.h>
#include <stdlib.h>

void solve ( int N, int M, int Q, int * a, int * b, int * c, int * d ) {
    int res = 0;
    void rec ( int * A, int len ) {
        if ( len == N ) {
            int ans = 0;
            for ( int i = 0; i < Q; i ++ ) {
                if ( A [ b [ i ] - 1 ] - A [ a [ i ] - 1 ] == c [ i ] ) {
                    ans += d [ i ];
                }
            }
            if ( ans > res ) {
                res = ans;
            }
            return;
        }
        int last_max = 1;
        if ( len > 0 ) {
            last_max = A [ len - 1 ];
        }
        for ( int i = last_max; i <= M; i ++ ) {
            int * B = ( int * ) malloc ( sizeof ( int ) * ( len + 1 ) );
            for ( int j = 0; j < len; j ++ ) {
                B [ j ] = A [ j ];
            }
            B [ len ] = i;
            rec ( B, len + 1 );
            free ( B );
        }
    }
    int * A = ( int * ) malloc ( sizeof ( int ) );
    rec ( A, 0 );
    printf ( "%d\n", res );
    free ( A );
}

int main ( ) {
    int N, M, Q;
    scanf ( "%d %d %d", & N, & M, & Q );
    int * a = ( int * ) malloc ( sizeof ( int ) * Q );
    int * b = ( int * ) malloc ( sizeof ( int ) * Q );
    int * c = ( int * ) malloc ( sizeof ( int ) * Q );
    int * d = ( int * ) malloc ( sizeof ( int ) * Q );
    for ( int i = 0; i < Q; i ++ ) {
        scanf ( "%d %d %d %d", & a [ i ], & b [ i ], & c [ i ], & d [ i ] );
    }
    solve ( N, M, Q, a, b, c, d );
    free ( a );
    free ( b );
    free ( c );
    free ( d );
    return 0;
}

