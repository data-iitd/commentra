
#include <stdio.h>
#define LUCKY "abcd"
int main ( ) {
    int n;
    scanf ( "%d", &n );
    char s [ n ];
    for ( int i = 0; i < n; i ++ ) {
        s [ i ] = LUCKY [ i % 4 ];
    }
    printf ( "%s\n", s );
    return 0;
}
// END-OF-CODE