
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main ( ) {
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    char s [ 100 ] ;
    char t [ 100 ] ;
    scanf ( "%s", s ) ;
    scanf ( "%s", t ) ;
    char * pch ;
    pch = strtok ( s, ":" ) ;
    int x [ 2 ] ;
    int y [ 2 ] ;
    int i = 0 ;
    while ( pch != NULL ) {
        x [ i ] = atoi ( pch ) ;
        pch = strtok ( NULL, ":" ) ;
        i++ ;
    }
    pch = strtok ( t, ":" ) ;
    i = 0 ;
    while ( pch != NULL ) {
        y [ i ] = atoi ( pch ) ;
        pch = strtok ( NULL, ":" ) ;
        i++ ;
    }

    // Step 2: Calculate the difference between the two times
    int diff = ( x [ 0 ] - y [ 0 ] ) * 60 + ( x [ 1 ] - y [ 1 ] ) ;
    printf ( "%d\n", diff ) ;

    return 0 ;
}

