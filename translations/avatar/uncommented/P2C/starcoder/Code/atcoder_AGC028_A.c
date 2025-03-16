#include <stdio.h>
#include <stdlib.h>
int main ( ) {
    int N, M, i, j, Kaburi_Size, counter, Flag = 0 ;
    scanf ( "%d %d", & N, & M ) ;
    char S [ 100000 ], T [ 100000 ] ;
    scanf ( "%s", S ) ;
    scanf ( "%s", T ) ;
    int Number_i [ N ], Number_iMN [ N ], Number_j [ M ], Kaburi_i [ N ], Kaburi_j [ M ] ;
    for ( i = 0 ; i < N ; i ++ ) {
        Number_i [ i ] = i ;
    }
    for ( i = 0 ; i < N ; i ++ ) {
        Number_iMN [ i ] = Number_i [ i ] * M / N ;
    }
    for ( j = 0 ; j < M ; j ++ ) {
        Number_j [ j ] = j ;
    }
    for ( j = 0 ; j < M ; j ++ ) {
        if ( Number_iMN [ j ] == Number_j [ j ] ) {
            Kaburi_j [ Kaburi_Size ] = Number_j [ j ] ;
            Kaburi_Size ++ ;
        }
    }
    for ( i = 0 ; i < N ; i ++ ) {
        if ( S [ i ] == T [ i ] ) {
            Kaburi_i [ i ] = i ;
        }
    }
    for ( counter = 0 ; counter < Kaburi_Size ; counter ++ ) {
        if ( S [ Kaburi_i [ counter ] ]!= T [ Kaburi_j [ counter ] ] ) {
            Flag = 1 ;
            break ;
        }
    }
    if ( Flag == 1 ) {
        printf ( "-1" ) ;
    }
    else {
        printf ( "%d", N * M / gcd ( N, M ) ) ;
    }
    return 0 ;
}
