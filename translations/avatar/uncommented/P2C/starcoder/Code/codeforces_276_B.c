#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    char s [ 1000000 ], c ;
    int i, j, k, l, cnt = 0 ;
    scanf ( "%s", s ) ;
    for ( i = 0 ; s [ i ]!= '\0' ; i ++ ) {
        for ( j = i + 1 ; s [ j ]!= '\0' ; j ++ ) {
            if ( s [ i ] == s [ j ] ) {
                cnt ++ ;
                for ( k = j + 1, l = j + 1 ; s [ k ]!= '\0' ; k ++ ) {
                    if ( s [ k ] == s [ l ] ) {
                        cnt ++ ;
                        l ++ ;
                    }
                }
            }
        }
    }
    if ( cnt % 2 == 0 ) {
        printf ( "First\n" ) ;
    }
    else {
        printf ( "Second\n" ) ;
    }
    return 0 ;
}
