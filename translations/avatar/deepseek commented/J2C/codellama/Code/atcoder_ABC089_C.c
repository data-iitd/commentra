
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ;
    long cnt [ 5 ] ;
    char str [ 100 ] ;
    // Declare variables.

    scanf ( "%d" , &n ) ;
    memset ( cnt , 0 , sizeof ( cnt ) ) ;
    // Read the number of strings and initialize the count array.

    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%s" , str ) ;
        if ( str [ 0 ] == 'M' ) {
            cnt [ 0 ] ++ ;
        } else if ( str [ 0 ] == 'A' ) {
            cnt [ 1 ] ++ ;
        } else if ( str [ 0 ] == 'R' ) {
            cnt [ 2 ] ++ ;
        } else if ( str [ 0 ] == 'C' ) {
            cnt [ 3 ] ++ ;
        } else if ( str [ 0 ] == 'H' ) {
            cnt [ 4 ] ++ ;
        }
        // Count the occurrences of each character at the start of the strings.
    }

    long res = cnt [ 0 ] * cnt [ 1 ] * cnt [ 2 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 2 ] * cnt [ 3 ] * cnt [ 4 ] ;
    printf ( "%ld\n" , res ) ;
    // Calculate the number of combinations and print the result.

    return 0 ;
}

