
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int h, a, num = 0 ;
    char str [ 100 ] ;

    scanf ( "%s", str ) ;
    sscanf ( str, "%d %d", &h, &a ) ;

    for ( int i = 1 ; h > 0 ; i ++ ) {
        h = h - a ;
        num ++ ;
    }

    printf ( "%d\n", num ) ;

    return 0 ;
}

