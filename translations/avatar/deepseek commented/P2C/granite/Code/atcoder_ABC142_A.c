

#include <stdio.h>
#include <math.h>

int main ( ) {
    int n = 0;
    scanf ( "%d", &n );
    int t = 0;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( i + 1 & 1 ) {
            t += 1;
        }
    }
    printf ( "%f", ( double ) t / n );
    return 0;
}

// END-OF-CODE