#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int N, n [ 1000 ], a = 1, pos = 0;
    scanf ( "%d", &N );
    for ( int i = 0 ; i < N ; i++ ) {
        scanf ( "%d", &n [ i ] );
    }
    for ( int i = 1 ; i < N ; i++ ) {
        if ( n [ pos ] > n [ i ] ) {
            a += 1;
            pos = i;
        }
    }
    printf ( "%d\n", a );
    return 0;
}
