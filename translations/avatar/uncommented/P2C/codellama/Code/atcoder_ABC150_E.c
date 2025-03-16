#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define mod 1000000007
int main ( ) {
    int n, i, j, k, c [ 1000000000 ], b, a, ans;
    scanf ( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf ( "%d", &c [ i ] );
    }
    for ( i = n - 1; i >= 0; i-- ) {
        for ( j = i - 1; j >= 0; j-- ) {
            if ( c [ j ] < c [ i ] ) {
                k = c [ j ];
                c [ j ] = c [ i ];
                c [ i ] = k;
            }
        }
    }
    b = pow ( 2, 2 * n - 2, mod );
    a = 2 * b % mod;
    ans = 0;
    for ( i = 0; i < n; i++ ) {
        ans += c [ i ] * ( a + i * b );
        ans %= mod;
    }
    printf ( "%d", ans );
    return 0;
}
