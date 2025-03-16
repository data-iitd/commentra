#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main ( int argc, char * argv [ ] ) {
    int N ;
    scanf ( "%d", & N ) ;
    int A [ N ] ;
    for ( int n = 0 ; n < N ; n ++ ) {
        scanf ( "%d", & A [ n ] ) ;
    }
    qsort ( A, N, sizeof ( int ), cmpfunc ) ;
    int min = A [ 0 ] ;
    int max = A [ N - 1 ] ;
    int mins = 0 ;
    int maxs = 0 ;
    for ( int value = 0 ; value < N ; value ++ ) {
        if ( A [ value ] == min ) {
            mins ++ ;
        }
        if ( A [ value ] == max ) {
            maxs ++ ;
        }
    }
    if ( min == max ) {
        long result = ( max - min ) + 1 ;
        result *= mins ;
        result -= mins * ( mins - 1 ) / 2 ;
        printf ( "%ld\n", result ) ;
    } else {
        long result = ( max - min ) ;
        result *= mins ;
        result *= maxs ;
        printf ( "%ld\n", result ) ;
    }
    return 0 ;
}

int cmpfunc ( const void * a, const void * b ) {
    return ( *( int * ) a - *( int * ) b ) ;
}

