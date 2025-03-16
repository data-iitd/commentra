#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int a [ ], i, e ;
    for ( i = 0 ; i < 10 ; i ++ ) {
        scanf ( "%d", &a [ i ] ) ;
    }
    for ( e = 0 ; e < 10 ; e ++ ) {
        if ( a [ e ] == 0 ) {
            printf ( "%d", e + 1 ) ;
            break ;
        }
    }
    return 0 ;
}
