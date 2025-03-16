#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int t, k, a, b, c;
    scanf ( "%d", &t );
    for ( int i = 0; i < t; i++ ) {
        scanf ( "%d %d %d", &a, &b, &c );
        k = a / b;
        if ( k * c >= a ) {
            printf ( "Yes\n" );
        } else {
            printf ( "No\n" );
        }
    }
    return 0;
}
