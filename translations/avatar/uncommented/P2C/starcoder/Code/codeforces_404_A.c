#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n, i, j, flag = 0, d1 [ ], d2 [ ], rem [ ];
    char s [ 1000 ] [ 1000 ], k;
    scanf ( "%d", &n );
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%s", s [ i ] );
    }
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = 0 ; j < n ; j++ ) {
            if ( i == j ) {
                d1 [ i ] = s [ i ] [ j ];
            }
            if ( i == n - j - 1 ) {
                d2 [ i ] = s [ i ] [ j ];
            }
            if ( i!= j && i!= n - j - 1 ) {
                rem [ i ] = s [ i ] [ j ];
            }
        }
    }
    if ( strlen ( rem )!= 1 ) {
        printf ( "NO\n" );
    }
    else if ( strcmp ( d1, d2 )!= 0 ) {
        printf ( "NO\n" );
    }
    else if ( strlen ( d1 )!= 1 ) {
        printf ( "NO\n" );
    }
    else if ( strcmp ( d1, rem ) == 0 ) {
        printf ( "NO\n" );
    }
    else {
        printf ( "YES\n" );
    }
    return 0;
}
