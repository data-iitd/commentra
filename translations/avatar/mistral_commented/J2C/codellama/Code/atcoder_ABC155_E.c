
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 1000000000000000

int main ( ) {
    char number [ 100 ] ;
    int digits [ 100 ] ;
    int bills = 0 ;
    int i ;

    scanf ( "%s", number ) ;

    for ( i = 0 ; i < strlen ( number ) ; i ++ ) {
        digits [ i ] = number [ strlen ( number ) - 1 - i ] - '0' ;
    }

    for ( i = 0 ; i <= strlen ( number ) ; i ++ ) {
        if ( digits [ i ] == 10 ) {
            digits [ i + 1 ] ++ ;
            digits [ i ] = 0 ;
        }

        if ( digits [ i ] < 5 ) {
            bills += digits [ i ] ;
        } else if ( digits [ i ] == 5 ) {
            if ( digits [ i + 1 ] >= 5 ) {
                digits [ i + 1 ] ++ ;
            }
            bills += 5 ;
        } else {
            digits [ i + 1 ] ++ ;
            bills += 10 - digits [ i ] ;
        }
    }

    printf ( "%d\n", bills ) ;

    return 0 ;
}

