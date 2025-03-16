

#include <stdio.h>
#include <string.h>

void solve ( char * S, char * T, int A, int B, char * U ) {
    // Check if the string S is equal to the string U
    if ( strcmp ( S, U ) == 0 ) {
        // Decrement the count of A by 1
        A -= 1;
    }
    // Check if the string T is equal to the string U
    if ( strcmp ( T, U ) == 0 ) {
        // Decrement the count of B by 1
        B -= 1;
    }
    // Print the updated counts of A and B
    printf ( "%d %d\n", A, B );
    return;
}

int main ( ) {
    char S [ 1000001 ] ;
    char T [ 1000001 ] ;
    int A ;
    int B ;
    char U [ 1000001 ] ;
    scanf ( "%s %s %d %d %s", S, T, & A, & B, U );
    // Call the solve function with the read inputs
    solve ( S, T, A, B, U );
    return 0;
}
// END-OF-CODE