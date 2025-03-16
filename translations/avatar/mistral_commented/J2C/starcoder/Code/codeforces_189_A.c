
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, c, maxn = 4010, dp [ maxn ] ;

    scanf ( "%d", &n ) ;

    scanf ( "%d", &a ) ;
    scanf ( "%d", &b ) ;
    scanf ( "%d", &c ) ;

    dp [ 0 ] = 0 ;

    for ( int i = 0 ; i < 3 ; i ++ ) {
        for ( int j = a ; j < maxn ; j ++ ) {
            dp [ j ] = ( dp [ j ] > dp [ j - a ] + 1 )? dp [ j ] : dp [ j - a ] + 1 ;
        }
    }

    for ( int i = 0 ; i < 3 ; i ++ ) {
        for ( int j = b ; j < maxn ; j ++ ) {
            dp [ j ] = ( dp [ j ] > dp [ j - b ] + 1 )? dp [ j ] : dp [ j - b ] + 1 ;
        }
    }

    for ( int i = 0 ; i < 3 ; i ++ ) {
        for ( int j = c ; j < maxn ; j ++ ) {
            dp [ j ] = ( dp [ j ] > dp [ j - c ] + 1 )? dp [ j ] : dp [ j - c ] + 1 ;
        }
    }

    printf ( "%d\n", dp [ n ] ) ;

    return 0 ;
}

