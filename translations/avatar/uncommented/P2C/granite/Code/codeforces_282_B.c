
#include <stdio.h>

int main ( ) {
    int firstline;
    scanf ( "%d", &firstline );
    int total = 0;
    char memory [ 501 ];
    for ( int x = 0 ; x < firstline ; x ++ ) {
        int A, G;
        scanf ( "%d %d", &A, &G );
        if ( total + A <= 500 ) {
            total += A;
            memory [ x ] = 'A';
        } else {
            total -= G;
            memory [ x ] = 'G';
        }
    }
    for ( int x = 0 ; x < firstline ; x ++ ) {
        printf ( "%c", memory [ x ] );
    }
    printf ( "\n" );
    return 0;
}
