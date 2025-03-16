
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    char s [ 100001 ];
    scanf ( "%s", s );
    int k;
    scanf ( "%d", & k );
    int l = 0;
    for ( int i = 0; s [ i ]!= '\0'; i ++ ) {
        if ( s [ i ]!= '1' ) {
            break;
        }
        l += 1;
    }
    if ( l >= k ) {
        printf ( "1\n" );
    } else {
        printf ( "%c\n", s [ l ] );
    }
    return 0;
}
// END-OF-CODE