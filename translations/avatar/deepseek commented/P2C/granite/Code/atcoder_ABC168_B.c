

#include <stdio.h>
#include <string.h>

char* main ( ) {
    // Read the value of K from the user
    int K;
    scanf ( "%d", & K ) ;
    // Read the string S from the user
    char S [ 1000 ] ;
    scanf ( "%s", S ) ;
    // Check if the length of S is less than or equal to K
    if ( strlen ( S ) <= K ) {
        // If the length of S is less than or equal to K, return S as it is
        return S ;
    }
    // If the length of S is greater than K, return the first K characters of S followed by '...'
    char* result = ( char* ) malloc ( K + 4 * sizeof ( char ) ) ;
    strncpy ( result, S, K ) ;
    strcpy ( result + K, "..." ) ;
    return result ;
}

int main ( ) {
    // Print the result of the main function
    printf ( "%s\n", main ( ) ) ;
    return 0 ;
}
