#include <stdio.h>
#include <stdlib.h>

int sum ( int a ) {
    int ans = 0 ;
    while ( a >= 10 ) {
        ans += a % 10 ;
        a /= 10 ;
    }
    ans += a ;
    return ans ;
}

int main ( int argc, char * argv [ ] ) {
    int N = atoi ( argv [ 1 ] ) ;
    int n = 0 ;
    if ( N % 2 == 0 ) {
        n = N / 2 ;
    } else {
        n = ( N + 1 ) / 2 ;
    }
    int ans = sum ( 1 ) + sum ( N - 1 ) ;
    for ( int A = 1 ; A <= n ; A ++ ) {
        if ( sum ( A ) + sum ( N - A ) < ans ) {
            ans = sum ( A ) + sum ( N - A ) ;
        }
    }
    printf ( "%d\n", ans ) ;
    return 0 ;
}

