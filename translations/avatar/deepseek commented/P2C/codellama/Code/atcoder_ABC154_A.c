
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void solve ( char *S , char *T , int A , int B , char *U ) {
    // Check if the string S is equal to the string U
    if ( strcmp ( S , U ) == 0 ) {
        // Decrement the count of A by 1
        A -= 1;
    }
    // Check if the string T is equal to the string U
    if ( strcmp ( T , U ) == 0 ) {
        // Decrement the count of B by 1
        B -= 1;
    }
    // Print the updated counts of A and B
    printf ( "%d %d\n" , A , B );
    return;
}

int main ( ) {
    // Read the string S
    char *S = malloc ( 100 * sizeof ( char ) );
    scanf ( "%s" , S );
    // Read the string T
    char *T = malloc ( 100 * sizeof ( char ) );
    scanf ( "%s" , T );
    // Read the integer A
    int A;
    scanf ( "%d" , &A );
    // Read the integer B
    int B;
    scanf ( "%d" , &B );
    // Read the string U
    char *U = malloc ( 100 * sizeof ( char ) );
    scanf ( "%s" , U );
    // Call the solve function with the read inputs
    solve ( S , T , A , B , U );
    return 0;
}

