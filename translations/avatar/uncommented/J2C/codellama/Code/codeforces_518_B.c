
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main ( ) {
    char *s = malloc ( 1000000 * sizeof ( char ) ) ;
    char *t = malloc ( 1000000 * sizeof ( char ) ) ;
    scanf ( "%s %s" , s , t ) ;
    int ura = 0 ;
    int opa = 0 ;
    int length = strlen ( s ) ;
    for ( int i = 0 ; i < length ; i ++ ) {
        if ( islower ( s [ i ] ) ) {
            s [ i ] = toupper ( s [ i ] ) ;
            ura ++ ;
        } else if ( isupper ( s [ i ] ) ) {
            s [ i ] = tolower ( s [ i ] ) ;
            opa ++ ;
        }
    }
    for ( int i = 0 ; i < length ; i ++ ) {
        if ( islower ( t [ i ] ) ) {
            t [ i ] = toupper ( t [ i ] ) ;
            ura ++ ;
        } else if ( isupper ( t [ i ] ) ) {
            t [ i ] = tolower ( t [ i ] ) ;
            opa ++ ;
        }
    }
    printf ( "%d %d" , ura , opa ) ;
    return 0 ;
}
