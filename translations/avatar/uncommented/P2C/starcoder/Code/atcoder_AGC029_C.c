#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000000
int main ( ) {
    int A [ MAX + 10 ];
    int N;
    scanf ( "%d", &N );
    for ( int i = 0 ; i < N ; i ++ ) {
        scanf ( "%d", &A [ i ] );
    }
    A [ N ] = 0;
    int dp [ MAX + 10 ];
    dp [ 0 ] = 0;
    for ( int i = 1 ; i <= N ; i ++ ) {
        if ( A [ i ] <= dp [ 0 ] ) {
            dp [ 0 ] = A [ i ];
        }
        else {
            int j = 0;
            while ( j < i && A [ i ] > dp [ j ] ) {
                j ++;
            }
            for ( int k = i ; k > j ; k -- ) {
                dp [ k ] = dp [ j ];
            }
            dp [ j ] = A [ i ];
        }
    }
    int ans = 0;
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( dp [ i ] < A [ i ] ) {
            ans = i;
            break;
        }
    }
    printf ( "%d\n", ans );
    return 0;
}
