#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MOD 1000000007
#define N 100000
#define M 1000000
#define Nsq 1000
int main ( ) {
    int i, j, n, ans, temp, inv [ N ];
    long long int fact [ M ];
    char str [ N ];
    scanf ( "%s" , str );
    int A [ N ];
    for ( i = 0 ; i < N ; i ++ ) {
        A [ i ] = str [ i ] - '0';
    }
    for ( i = 0 ; i < Nsq ; i ++ ) {
        for ( j = 0 ; j < Nsq ; j ++ ) {
            fact [ i * Nsq + j ] = 1;
        }
    }
    for ( i = 1 ; i < Nsq ; i ++ ) {
        for ( j = 0 ; j < Nsq ; j ++ ) {
            fact [ i * Nsq + j ] *= fact [ ( i - 1 ) * Nsq + j ];
            fact [ i * Nsq + j ] %= MOD;
        }
    }
    for ( i = 1 ; i < Nsq ; i ++ ) {
        for ( j = 0 ; j < Nsq ; j ++ ) {
            fact [ i * Nsq + j ] *= fact [ ( i - 1 ) * Nsq + j - 1 ];
            fact [ i * Nsq + j ] %= MOD;
        }
    }
    for ( i = 0 ; i < N ; i ++ ) {
        inv [ i ] = pow ( i + 1 , MOD - 2 , MOD );
    }
    for ( i = 0 ; i < N ; i ++ ) {
        inv [ i ] += inv [ N - 1 - i ];
        inv [ i ] %= MOD;
    }
    for ( i = 0 ; i < N ; i ++ ) {
        temp = inv [ i ] + inv [ N - 1 - i ] - 1;
        temp %= MOD;
        ans += ( A [ i ] * temp % MOD );
        ans %= MOD;
    }
    ans *= fact [ N ];
    ans %= MOD;
    printf ( "%d\n" , ans );
    return 0;
}
