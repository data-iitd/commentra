#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MOD 1000000007
#define N 1000000
#define Nsq 1000
int main ( ) {
    int N;
    scanf ( "%d", &N ) ;
    int A [ N ] ;
    for ( int i = 0 ; i < N ; i ++ )
        scanf ( "%d", &A [ i ] ) ;
    int M = 1000000 ;
    int fact [ M ] ;
    fact [ 0 ] = 1 ;
    for ( int n = 1 ; n < M ; n ++ )
        fact [ n ] = ( fact [ n - 1 ] * n ) % MOD ;
    int inv [ N ] ;
    inv [ 0 ] = 1 ;
    for ( int i = 1 ; i < N ; i ++ )
        inv [ i ] = ( inv [ i - 1 ] * ( i + 1 ) ) % MOD ;
    for ( int i = 1 ; i < N ; i ++ )
        inv [ i ] = ( inv [ i ] * inv [ i - 1 ] ) % MOD ;
    for ( int i = 0 ; i < N ; i ++ )
        inv [ i ] = ( inv [ i ] + MOD - 1 ) % MOD ;
    int j [ N ] ;
    for ( int i = 0 ; i < N ; i ++ )
        j [ i ] = i ;
    for ( int i = 0 ; i < N ; i ++ ) {
        int temp = inv [ j [ i ] ] + inv [ N - 1 - j [ i ] ] - 1 ;
        A [ i ] = ( A [ i ] * temp ) % MOD ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < N ; i ++ )
        ans = ( ans + A [ i ] ) % MOD ;
    ans = ( ans * fact [ N ] ) % MOD ;
    printf ( "%d\n", ans ) ;
    return 0 ;
}
