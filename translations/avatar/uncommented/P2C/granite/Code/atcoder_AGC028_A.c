
#include <stdio.h>
#include <math.h>

int main ( void ) {
    int N, M ;
    scanf ( "%d %d", &N, &M ) ;
    char S [ N ] ;
    char T [ M ] ;
    scanf ( "%s %s", S, T ) ;
    int i ;
    int j ;
    int Number_i [ N ] ;
    int Number_j [ M ] ;
    for ( i = 0 ; i < N ; i ++ ) {
        Number_i [ i ] = i * M / N ;
    }
    for ( j = 0 ; j < M ; j ++ ) {
        Number_j [ j ] = j * N / M ;
    }
    int Kaburi_i [ N ] ;
    int Kaburi_j [ M ] ;
    int Kaburi_Size = 0 ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < M ; j ++ ) {
            if ( Number_i [ i ] == Number_j [ j ] ) {
                Kaburi_i [ Kaburi_Size ] = i ;
                Kaburi_j [ Kaburi_Size ] = j ;
                Kaburi_Size ++ ;
            }
        }
    }
    int counter = 0 ;
    int Flag = 0 ;
    while ( counter < Kaburi_Size ) {
        if ( S [ Kaburi_i [ counter ] ]!= T [ Kaburi_j [ counter ] ] ) {
            Flag = 1 ;
            break ;
        }
        counter ++ ;
    }
    if ( Flag == 1 ) {
        printf ( "-1\n" ) ;
    } else {
        int gcd ( int a, int b ) ;
        printf ( "%d\n", ( int ) ( ( double ) N * M / gcd ( N, M ) ) ) ;
    }
    return 0 ;
}

int gcd ( int a, int b ) {
    while ( b > 0 ) {
        a = b ;
        b = a % b ;
    }
    return a ;
}

