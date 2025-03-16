#include <stdio.h>
#include <string.h>

int main ( ) {
    int K;
    char S [ 1000 ];
    scanf ( "%d", &K );
    scanf ( "%s", S );
    if ( strlen ( S ) <= K ) {
        printf ( "%s", S );
    } else {
        printf ( "%.*s...", K, S );
    }
    return 0;
}
