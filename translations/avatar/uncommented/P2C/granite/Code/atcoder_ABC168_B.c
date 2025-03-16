
#include <stdio.h>
#include <string.h>

char* main ( ) {
    int K;
    char S [ 1000 ];
    scanf ( "%d", & K );
    scanf ( "%s", S );
    if ( strlen ( S ) <= K ) {
        return S;
    }
    return strcat ( strcat ( strcat ( "", S ), "..." ), "\0" );
}

int main ( ) {
    printf ( "%s\n", main ( ) );
    return 0;
}

