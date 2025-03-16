

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( void ) {
    int N ;
    scanf ( "%d", & N ) ;

    char ** map = ( char ** ) malloc ( N * sizeof ( char * ) ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        map [ i ] = ( char * ) malloc ( 100 * sizeof ( char ) ) ;
        scanf ( "%s", map [ i ] ) ;
    }

    int * past = ( int * ) malloc ( N * sizeof ( int ) ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        past [ i ] = -1 ;
    }

    char next = '\0' ;
    bool ans = true ;
    for ( int i = 0 ; i < N ; i ++ ) {
        for ( int j = 0 ; j < i ; j ++ ) {
            if ( strcmp ( map [ i ], map [ j ] ) == 0 ) {
                ans = false ;
                break ;
            }
        }
        if (! ans ) {
            break ;
        }
        past [ i ] = 1 ;
        if ( i!= 0 ) {
            if ( map [ i ] [ 0 ]!= next ) {
                ans = false ;
                break ;
            }
        }
        next = map [ i ] [ strlen ( map [ i ] ) - 1 ] ;
    }

    if ( ans ) {
        printf ( "Yes\n" ) ;
    } else {
        printf ( "No\n" ) ;
    }

    for ( int i = 0 ; i < N ; i ++ ) {
        free ( map [ i ] ) ;
    }
    free ( map ) ;
    free ( past ) ;

    return 0 ;
}
