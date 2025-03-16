
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, t = 0;
    scanf ( "%d", &n );
    for ( int i = 0; i < n; i++ ) {
        if ( ( i + 1 ) & 1 ) t++;
    }
    printf ( "%.6f\n", ( double ) t / n );
    return 0;
}

