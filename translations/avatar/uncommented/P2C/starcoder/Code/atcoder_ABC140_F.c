#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main ( ) {
    int N;
    scanf ( "%d", &N );
    int S [ N ];
    for ( int i = 0 ; i < N ; i ++ )
        scanf ( "%d", &S [ i ] );
    qsort ( S, N, sizeof ( int ), ( int * ) ( * ( int * ) ( ) ) ( __builtin_cmp ) );
    bool flag [ N ];
    for ( int i = 0 ; i < N ; i ++ )
        flag [ i ] = true;
    int cur [ N ];
    int j = 0;
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( flag [ i ] ) {
            cur [ j ] = S [ i ];
            j ++;
        }
    }
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( flag [ i ] ) {
            for ( int k = 0 ; k < N ; k ++ ) {
                if (! flag [ k ] && S [ k ] < cur [ j - 1 ] ) {
                    cur [ j ] = S [ k ];
                    j ++;
                    flag [ k ] = false;
                    break;
                }
            }
        }
    }
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( flag [ i ] ) {
            printf ( "No" );
            return 0;
        }
    }
    printf ( "Yes" );
    return 0;
}
