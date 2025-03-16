#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define mod 1000000007
int main ( ) {
    int n;
    scanf ( "%d", &n );
    int c [ n ];
    for ( int i = 0 ; i < n ; i ++ )
        scanf ( "%d", &c [ i ] );
    qsort ( c, n, sizeof ( int ), cmpfunc );
    int b = pow ( 2, 2 * n - 2, mod );
    int a = 2 * b % mod;
    int ans = 0;
    for ( int i = 0 ; i < n ; i ++ )
        ans += c [ i ] * ( a + i * b );
    printf ( "%d\n", ans % mod );
    return 0;
}
int cmpfunc ( const void * a, const void * b ) {
    return ( *( int * ) b - *( int * ) a );
}
