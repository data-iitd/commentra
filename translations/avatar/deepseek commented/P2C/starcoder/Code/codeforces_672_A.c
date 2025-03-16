
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int li [ ] = { 0 }, ind = 0, i, p, q, count, temp [ ] = { 0 } ;
    for ( i = 1 ; i <= 371 ; i++ ) {
        p = i, q = i, count = 0 ;
        while ( p!= 0 ) {
            p /= 10 ;
            count++ ;
        }
        if ( count == 1 ) {
            li [ ind++ ] = i ;
        }
        if ( count == 2 ) {
            while ( q!= 0 ) {
                temp [ ind++ ] = q % 10 ;
                q /= 10 ;
            }
            for ( int j = ind - 1 ; j >= 0 ; j-- ) {
                li [ ind++ ] = temp [ j ] ;
            }
        }
        if ( count == 3 ) {
            while ( q!= 0 ) {
                temp [ ind++ ] = q % 10 ;
                q /= 10 ;
            }
            for ( int j = ind - 1 ; j >= 0 ; j-- ) {
                li [ ind++ ] = temp [ j ] ;
            }
        }
    }
    li [ --ind ] = 0 ;
    li [ --ind ] = 0 ;
    int n ;
    scanf ( "%d", &n ) ;
    printf ( "%d\n", li [ n - 1 ] ) ;
    return 0 ;
}

