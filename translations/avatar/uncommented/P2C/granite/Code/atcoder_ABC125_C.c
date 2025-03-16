
#include <stdio.h>
#include <stdlib.h>

int gcd ( int a, int b ) {
    if ( b == 0 ) {
        return a;
    }
    return gcd ( b, a % b );
}

void ruiseki_lr ( int array [ ], int n, int left [ ], int right [ ] ) {
    int e = 0;
    int i;
    int (*op) ( int, int ) = &gcd;
    left [ 0 ] = e;
    for ( i = 0; i < n; i ++ ) {
        left [ i + 1 ] = op ( left [ i ], array [ i ] );
    }
    right [ n ] = e;
    for ( i = n - 1; i >= 0; i -- ) {
        right [ i ] = op ( right [ i + 1 ], array [ i ] );
    }
}

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int a [ n ];
    int i;
    for ( i = 0; i < n; i ++ ) {
        scanf ( "%d", &a [ i ] );
    }
    int left [ n + 1 ];
    int right [ n + 1 ];
    ruiseki_lr ( a, n, left, right );
    int ans = 0;
    for ( i = 0; i < n; i ++ ) {
        ans = ans < gcd ( left [ i ], right [ i + 1 ] )? gcd ( left [ i ], right [ i + 1 ] ) : ans;
    }
    printf ( "%d\n", ans );
    return 0;
}
