
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int A, B, n, X;
    scanf ( "%d %d %d", &A, &B, &n );
    for ( X = - 1000 ; X <= 1000 ; X ++ ) {
        if ( A * ( X ** n ) == B ) {
            printf ( "%d", X );
            return 0;
        }
    }
    printf ( "No solution" );
    return 0;
}
