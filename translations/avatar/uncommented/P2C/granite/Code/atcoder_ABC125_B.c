
#include <stdio.h>

int main ( ) {
    int N;
    scanf ( "%d", &N );
    int V [ N ];
    int C [ N ];
    for ( int i = 0; i < N; i ++ ) {
        scanf ( "%d", &V [ i ] );
    }
    for ( int i = 0; i < N; i ++ ) {
        scanf ( "%d", &C [ i ] );
    }
    int list [ N ];
    int ans = 0;
    int X = 0;
    int Y = 0;
    for ( int i = 0; i < N; i ++ ) {
        if ( V [ i ] - C [ i ] > 0 ) {
            X = V [ i ];
            Y = C [ i ];
            list [ i ] = X - Y;
        }
    }
    for ( int i = 0; i < N; i ++ ) {
        ans += list [ i ];
    }
    printf ( "%d", ans );
    return 0;
}
