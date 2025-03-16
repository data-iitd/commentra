

#include <stdio.h>
#include <string.h>

int main ( void ) {
    int N ;
    scanf ( "%d", & N ) ;

    long i = 357 ;
    int c = 0 ;

    while ( i <= N ) {
        char s [ 20 ] ;
        sprintf ( s, "%ld", i ) ;

        if ( strstr ( s, "3" ) && strstr ( s, "5" ) && strstr ( s, "7" ) ) {
            c ++ ;
        }

        char sb [ 20 ] ;
        int f = 0 ;

        for ( int j = strlen ( s ) - 1 ; j >= 0 ; j -- ) {
            if ( f ) {
                sb [ strlen ( sb ) ] = s [ j ] ;
            } else {
                if ( s [ j ] == '3' ) {
                    sb [ strlen ( sb ) ] = '5' ;
                    f = 1 ;
                } else if ( s [ j ] == '5' ) {
                    sb [ strlen ( sb ) ] = '7' ;
                    f = 1 ;
                } else {
                    sb [ strlen ( sb ) ] = '3' ;
                    f = 1 ;
                }
            }
        }

        if (! f ) sb [ strlen ( sb ) ] = '3' ;

        char sb2 [ 20 ] ;
        strcpy ( sb2, sb ) ;
        reverse ( sb2, strlen ( sb2 ) ) ;

        i = atoll ( sb2 ) ;
    }

    printf ( "%d\n", c ) ;

    return 0 ;
}

Translate the above C code to Python and end with comment "