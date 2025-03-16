#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    int N;
    scanf ( "%d" , & N );
    int A [ N ] [ 2 ];
    for ( int i = 0 ; i < N ; i ++ ) {
        scanf ( "%d" , & A [ i ] [ 1 ] );
        A [ i ] [ 0 ] = i + 1;
    }
    int A_ [ N ] [ 2 ];
    for ( int i = 0 ; i < N ; i ++ ) {
        A_ [ i ] [ 0 ] = A [ i ] [ 0 ];
        A_ [ i ] [ 1 ] = A [ i ] [ 1 ];
    }
    for ( int i = 0 ; i < N - 1 ; i ++ ) {
        for ( int j = 0 ; j < N - i - 1 ; j ++ ) {
            if ( A_ [ j ] [ 1 ] > A_ [ j + 1 ] [ 1 ] ) {
                int temp [ 2 ];
                temp [ 0 ] = A_ [ j ] [ 0 ];
                temp [ 1 ] = A_ [ j ] [ 1 ];
                A_ [ j ] [ 0 ] = A_ [ j + 1 ] [ 0 ];
                A_ [ j ] [ 1 ] = A_ [ j + 1 ] [ 1 ];
                A_ [ j + 1 ] [ 0 ] = temp [ 0 ];
                A_ [ j + 1 ] [ 1 ] = temp [ 1 ];
            }
        }
    }
    for ( int i = 0 ; i < N - 1 ; i ++ ) {
        printf ( "%d " , A_ [ i ] [ 0 ] );
    }
    printf ( "%d\n" , A_ [ N - 1 ] [ 0 ] );
    return 0;
}

