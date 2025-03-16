
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int max = 0 ;
    int n ;
    int *beacon = ( int * ) malloc ( 1000001 * sizeof ( int ) ) ;
    int *dp = ( int * ) malloc ( 1000001 * sizeof ( int ) ) ;
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int a ;
        scanf ( "%d" , &a ) ;
        beacon [ a ] = i ;
    }
    if ( beacon [ 0 ] != 0 ) dp [ 0 ] = 1 ;
    for ( int i = 1 ; i < 1000001 ; i ++ ) {
        if ( beacon [ i ] != 0 && beacon [ i ] < i ) {
            dp [ i ] = dp [ i - beacon [ i ] - 1 ] + 1 ;
        } else if ( beacon [ i ] != 0 ) {
            dp [ i ] = 1 ;
        } else {
            dp [ i ] = dp [ i - 1 ] ;
        }
        max = max < dp [ i ] ? dp [ i ] : max ;
    }
    printf ( "%d" , n - max ) ;
    return 0 ;
}

