
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main ( ) {
    int N, M, i, j, Kaburi_Size, Flag = 0, counter = 0 ;
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
            Kaburi_j [ counter ] = Number_j [ j ] ;
            counter ++ ;
        }
    }
    Kaburi_Size = counter ;
    for ( i = 0 ; i < Kaburi_Size ; i ++ ) {
        Kaburi_i [ i ] = Kaburi_j [ i ] * N / M ;
    }
    for ( i = 0 ; i < Kaburi_Size ; i ++ ) {
        if ( S [ Kaburi_i [ i ] ]!= T [ Kaburi_j [ i ] ] ) {
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
