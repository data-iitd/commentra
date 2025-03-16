
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int N;
    scanf ( "%d", & N );
    int * A = ( int * ) malloc ( sizeof ( int ) * N );
    for ( int i = 0; i < N; i ++ ) {
        int a;
        scanf ( "%d", & a );
        A [ i ] = a * N + i;
    }
    qsort ( A, N, sizeof ( int ) );
    int cnt = 0;
    for ( int i = 0; i < N; i ++ ) {
        int d = ( A [ i ] % N ) % 2;
        if ( d % 2!= i % 2 ) cnt += 1;
    }
    printf ( "%d\n", cnt / 2 );
    free ( A );
    return 0;
}
