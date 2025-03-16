
#include <stdio.h>

int main ( ) {
    int n, x = 0, y = 0, z = 0;
    scanf ( "%d", &n );
    int a [ n ], b [ n ], c [ n ];
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &a [ i ] );
        x += a [ i ];
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &b [ i ] );
        y += b [ i ];
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &c [ i ] );
        z += c [ i ];
    }
    printf ( "%d\n", abs ( x - y ) );
    printf ( "%d\n", abs ( y - z ) );
    return 0;
}
