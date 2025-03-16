
#include <stdio.h>

int main ( ) {
    int a, b ;
    scanf ( "%d %d", & a, & b ) ;
    if ( a > 0 ) {
        printf ( "Positive\n" ) ;
    }
    else if ( a <= 0 && b >= 0 ) {
        printf ( "Zero\n" ) ;
    }
    else {
        if ( ( a + b ) % 2 == 0 ) {
            printf ( "Negative\n" ) ;
        }
        else {
            printf ( "Positive\n" ) ;
        }
    }
    return 0 ;
}
//END-OF-CODE