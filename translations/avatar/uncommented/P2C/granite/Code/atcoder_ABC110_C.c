
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *run ( char *s, char *t ) {
    int *ss = ( int * ) malloc ( sizeof ( int ) * 26 ) ;
    int *tt = ( int * ) malloc ( sizeof ( int ) * 26 ) ;
    memset ( ss, 0, sizeof ( int ) * 26 ) ;
    memset ( tt, 0, sizeof ( int ) * 26 ) ;
    for ( int i = 0 ; s [ i ] ; i ++ ) {
        ss [ s [ i ] -'a'] ++ ;
    }
    for ( int i = 0 ; t [ i ] ; i ++ ) {
        tt [ t [ i ] -'a'] ++ ;
    }
    for ( int i = 0 ; i < 26 ; i ++ ) {
        if ( ss [ i ]!= tt [ i ] ) {
            free ( ss ) ;
            free ( tt ) ;
            return "No" ;
        }
    }
    free ( ss ) ;
    free ( tt ) ;
    return "Yes" ;
}

int main ( ) {
    char s [ 100001 ] ;
    char t [ 100001 ] ;
    scanf ( "%s", s ) ;
    scanf ( "%s", t ) ;
    printf ( "%s\n", run ( s, t ) ) ;
    return 0 ;
}

