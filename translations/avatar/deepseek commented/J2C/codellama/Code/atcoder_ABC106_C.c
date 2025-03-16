
#include <stdio.h>
#include <string.h>

int main ( ) {
    char str [ 100 ] ;
    int n ;
    long k ;
    char c [ 100 ] ;
    int i ;
    
    scanf ( "%s" , str ) ;
    n = strlen ( str ) ;
    k = str [ n - 1 ] - '0' ;
    strcpy ( c , str ) ;
    
    for ( i = 0 ; i < k ; i ++ ) {
        if ( c [ i ] == '1' ) {
            if ( i == k - 1 ) {
                printf ( "1" ) ;
                return 0 ;
            }
        } else {
            printf ( "%c" , c [ i ] ) ;
            return 0 ;
        }
    }
    
    return 0 ;
}

