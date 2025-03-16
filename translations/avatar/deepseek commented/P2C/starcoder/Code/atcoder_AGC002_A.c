#include <stdio.h>
int main ( ) {
    int a, b;
    scanf ( "%d %d", &a, &b );
    if ( a > 0 ) {
        printf ( "Positive" );
    }
    else if ( a <= 0 && b >= 0 ) {
        printf ( "Zero" );
    }
    else {
        if ( ( a + b ) % 2 == 0 ) {
            printf ( "Negative" );
        }
        else {
            printf ( "Positive" );
        }
    }
    return 0;
}
