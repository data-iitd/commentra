#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int C ( int n, int m ) {
    int res = 1 ;
    for ( int i = m - n + 1 ; i <= m ; i ++ ) res *= i ;
    for ( int i = 1 ; i <= n ; i ++ ) res /= i ;
    return res ;
}

int main ( int argc, char ** argv ) {
    int n, p ;
    int k0 = 0 ;
    int k1 = 0 ;
    scanf ( "%d %d", & n, & p ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        scanf ( "%d", & x ) ;
        if ( x % 2 == 1 ) k1 ++ ;
        else k0 ++ ;
    }
    int ans = 1 ;
    for ( int i = 0 ; i < k0 ; i ++ ) ans *= 2 ;
    if ( p == 0 ) {
        int add = 0 ;
        for ( int i = 0 ; i <= k1 ; i += 2 ) add += C ( i, k1 ) ;
        ans *= add ;
        printf ( "%d\n", ans ) ;
    } else {
        int add = 0 ;
        for ( int i = 1 ; i <= k1 ; i += 2 ) add += C ( i, k1 ) ;
        ans *= add ;
        printf ( "%d\n", ans ) ;
    }
    return 0 ;
}

