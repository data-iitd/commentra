#include <bits/stdc++.h>
using namespace std;
#define dprint(...)
#define mod 998244353
#define N 8000
int g1 [ N + 1 ], g2 [ N + 1 ], inverse [ N + 1 ] ;
int cmb ( int n, int r ) {
    if ( r < 0 or r > n ) return 0 ;
    r = min ( r, n - r ) ;
    return g1 [ n ] * g2 [ r ] * g2 [ n - r ] % mod ;
}
int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( 0 ) ;
    int K, N ;
    cin >> K >> N ;
    for ( int i = 2 ; i <= N ; i ++ ) {
        g1 [ i ] = ( g1 [ i - 1 ] * i ) % mod ;
        inverse [ i ] = ( - inverse [ mod % i ] * ( mod / i ) ) % mod ;
        g2 [ i ] = ( g2 [ i - 1 ] * inverse [ i - 1 ] ) % mod ;
    }
    for ( int i = 2 ; i <= 2 * K ; i ++ ) {
        if ( i <= K + 1 ) {
            cout << cmb ( i + K, i ) * kumiawase ( N, i ) % mod << " " ;
        }
        else {
            cout << ans [ - i + K ] << " " ;
        }
    }
    return 0 ;
}
