#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int t [ n + 1 ];
    int a [ n + 1 ];
    int ans [ n + 1 ];
    int cnt [ n + 1 ];
    for ( int i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d", &t [ i ] );
        scanf ( "%d", &a [ i ] );
        cnt [ a [ i ] ] += 1;
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( t [ i ] == 1 ) {
            int crt [ n + 1 ];
            int x = a [ i ];
            int j = 0;
            while ( cnt [ x ] == 1 ) {
                crt [ j ] = x;
                j ++;
                x = a [ x ];
            }
            if ( j > n ) {
                for ( int k = 0 ; k < n ; k ++ ) {
                    ans [ k ] = crt [ k ];
                }
                break;
            }
        }
    }
    printf ( "%d\n", n );
    for ( int i = 0 ; i < n ; i ++ ) {
        printf ( "%d ", ans [ i ] );
    }
    printf ( "\n" );
    return 0;
}
