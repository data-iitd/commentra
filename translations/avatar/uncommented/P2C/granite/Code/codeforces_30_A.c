
#include <stdio.h>
#include <math.h>

int task4 ( int A, int B, int n ) {
    for ( int X = - 1000 ; X <= 1000 ; X ++ ) {
        if ( A * pow ( X, n ) == B ) {
            return X;
        }
    }
    return - 1;
}

int main ( ) {
    int A, B, n ;
    scanf ( "%d %d %d", & A, & B, & n ) ;
    int X = task4 ( A, B, n ) ;
    if ( X == - 1 ) {
        printf ( "No solution" ) ;
    } else {
        printf ( "%d", X ) ;
    }
    return 0;
}

