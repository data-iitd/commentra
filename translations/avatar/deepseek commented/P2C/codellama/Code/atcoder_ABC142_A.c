
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int next_int ( ) {
    int x;
    scanf ( "%d" , &x );
    return x;
}

int *next_ints ( ) {
    int *x = malloc ( 100 * sizeof ( int ) );
    int i;
    for ( i = 0 ; i < 100 ; i++ ) {
        scanf ( "%d" , &x[i] );
    }
    return x;
}

int main ( ) {
    int n;
    int t = 0;
    int i;
    n = next_int ( );
    for ( i = 0 ; i < n ; i++ ) {
        if ( i + 1 & 1 ) {
            t += 1;
        }
    }
    printf ( "%d\n" , t / n );
    return 0;
}

