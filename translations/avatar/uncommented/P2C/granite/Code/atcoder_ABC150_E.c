
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int c [ n ];
    for ( int i = 0; i < n; i ++ ) scanf ( "%d", &c [ i ] );
    long long mod = 100000007;
    long long b = pow ( 2, 2 * n - 2 ) % mod;
    long long a = 2 * b % mod;
    long long ans = 0;
    for ( int i = 0; i < n; i ++ ) {
        ans += c [ i ] * ( a + i * b ) % mod;
        ans %= mod;
    }
    printf ( "%lld\n", ans );
    return 0;
}
