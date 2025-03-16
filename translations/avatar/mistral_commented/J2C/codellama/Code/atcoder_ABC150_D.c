
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, m, i, j, k, l, a [ 100000 ] ;
    long gcd, lcd = 1 ;

    scanf ( "%d %d", &n, &m ) ;

    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &a [ i ] ) ;
        a [ i ] /= 2 ;
    }

    for ( i = 0 ; i < n ; i ++ ) {
        gcd = getGCD ( lcd, a [ i ] ) ;
        lcd = lcd * a [ i ] / gcd ;

        if ( lcd > m ) {
            printf ( "0\n" ) ;
            return 0 ;
        }
    }

    for ( i = 0 ; i < n ; i ++ ) {
        if ( ( lcd / a [ i ] ) % 2 == 0 ) {
            printf ( "0\n" ) ;
            return 0 ;
        }
    }

    printf ( "%ld\n", ( m / lcd + 1 ) / 2 ) ;

    return 0 ;
}

long getGCD ( long a, long b ) {
    if ( b == 0 ) {
        return a ;
    } else {
        return getGCD ( b, a % b ) ;
    }
}

