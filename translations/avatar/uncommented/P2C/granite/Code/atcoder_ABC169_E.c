
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

void resolve ( ) {
    int n;
    scanf ( "%d", & n );
    int * low = ( int * ) malloc ( sizeof ( int ) * n );
    int * high = ( int * ) malloc ( sizeof ( int ) * n );
    for ( int i = 0; i < n; i ++ ) {
        int a, b;
        scanf ( "%d %d", & a, & b );
        low [ i ] = a;
        high [ i ] = b;
    }
    qsort ( low, n, sizeof ( int ), cmpfunc );
    qsort ( high, n, sizeof ( int ), cmpfunc );
    if ( n % 2 ) {
        printf ( "%d\n", high [ ( n + 1 ) / 2 - 1 ] - low [ ( n + 1 ) / 2 - 1 ] + 1 );
    } else {
        double hh = ( high [ ( n ) / 2 - 1 ] + high [ ( n ) / 2 ] ) / 2.0;
        double ll = ( low [ ( n ) / 2 - 1 ] + low [ ( n ) / 2 ] ) / 2.0;
        printf ( "%d\n", ( int ) ( ( hh - ll ) * 2 ) + 1 );
    }
}

int main ( ) {
    resolve ( );
    return 0;
}

END-OF-CODE