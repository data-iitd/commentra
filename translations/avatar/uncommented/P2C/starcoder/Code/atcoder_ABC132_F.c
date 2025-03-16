#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define mod 1000000007
int main ( ) {
    int n, k, nn ;
    scanf ( "%d%d", &n, &k ) ;
    int *coef = ( int * ) malloc ( sizeof ( int ) * n ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        coef [ i - 1 ] = ( n / i ) - ( n / ( i + 1 ) ) ;
    }
    nn = n ;
    int **dp = ( int ** ) malloc ( sizeof ( int * ) * ( k + 1 ) ) ;
    for ( int i = 0 ; i <= k ; i ++ ) {
        dp [ i ] = ( int * ) malloc ( sizeof ( int ) * nn ) ;
        memset ( dp [ i ], 0, sizeof ( int ) * nn ) ;
    }
    dp [ 0 ] [ 0 ] = 1 ;
    for ( int i = 1 ; i <= k ; i ++ ) {
        int tmp = 0 ;
        for ( int j = nn - 1 ; j >= 0 ; j -- ) {
            tmp += dp [ i - 1 ] [ j ] ;
            tmp %= mod ;
            dp [ i ] [ j ] = coef [ j ] * tmp ;
            dp [ i ] [ j ] %= mod ;
        }
    }
    printf ( "%d\n", dp [ k ] [ 0 ] ) ;
    return 0 ;
}
