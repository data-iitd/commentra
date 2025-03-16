
#include <stdio.h>

void solve ( char * S, char * T, int A, int B, char * U ) {
    if (strcmp ( S, U ) == 0) {
        A -= 1;
    }
    if (strcmp ( T, U ) == 0) {
        B -= 1;
    }
    printf ( "%d %d\n", A, B );
    return;
}

int main ( ) {
    char S [ 1000000 ] ;
    char T [ 1000000 ] ;
    int A ;
    int B ;
    char U [ 1000000 ] ;
    scanf ( "%s %s %d %d %s", S, T, & A, & B, U );
    solve ( S, T, A, B, U );
    return 0;
}

