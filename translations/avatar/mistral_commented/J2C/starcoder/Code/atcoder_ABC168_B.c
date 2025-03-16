
#include <stdio.h>
#include <string.h>

int main ( ) {

    int K ;
    scanf ( "%d", &K ) ;

    char S [ 100000 ] ;
    scanf ( "%s", S ) ;

    if ( strlen ( S ) <= K ) {

        printf ( "%s", S ) ;

    } else {

        printf ( "%.*s...", K, S ) ;

    }

    return 0 ;

}

