
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int N;
    scanf ( "%d", & N );
    int A [ N ];
    for ( int i = 0 ; i < N ; i ++ ) {
        scanf ( "%d", & A [ i ] );
    }
    int dp [ N ];
    dp [ 0 ] = 1;
    for ( int i = 1 ; i < N ; i ++ ) {
        dp [ i ] = 0;
        for ( int j = 0 ; j < i ; j ++ ) {
            if ( A [ j ] <= A [ i ] && dp [ j ] + 1 > dp [ i ] ) {
                dp [ i ] = dp [ j ] + 1;
            }
        }
    }
    int ans = 0;
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( ans < dp [ i ] ) {
            ans = dp [ i ];
        }
    }
    printf ( "%d\n", ans );
    return 0;
}
//END-OF-CODE