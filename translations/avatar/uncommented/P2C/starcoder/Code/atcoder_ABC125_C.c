#include <stdio.h>
#include <stdlib.h>
int gcd ( int a, int b ) {
    if ( b == 0 ) {
        return a;
    }
    return gcd ( b, a % b );
}
int main ( ) {
    int n, i, ans = 0;
    scanf ( "%d", &n );
    int *a = ( int * ) malloc ( sizeof ( int ) * n );
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &a [ i ] );
    }
    int *left = ( int * ) malloc ( sizeof ( int ) * ( n + 1 ) );
    int *right = ( int * ) malloc ( sizeof ( int ) * ( n + 1 ) );
    left [ 0 ] = 0;
    right [ n ] = 0;
    for ( i = 0 ; i < n ; i ++ ) {
        left [ i + 1 ] = gcd ( left [ i ], a [ i ] );
    }
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        right [ i ] = gcd ( right [ i + 1 ], a [ i ] );
    }
    for ( i = 0 ; i < n ; i ++ ) {
        ans = max ( gcd ( left [ i ], right [ i + 1 ] ), ans );
    }
    printf ( "%d", ans );
    return 0;
}
