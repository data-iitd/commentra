
#include <stdio.h>
#include <string.h>

int main ( ) {
    // Read the value of K from the user
    int K;
    scanf ( "%d", &K );
    // Read the string S from the user
    char S [ 1000 ];
    scanf ( "%s", S );
    // Check if the length of S is less than or equal to K
    if ( strlen ( S ) <= K ) {
        // If the length of S is less than or equal to K, return S as it is
        printf ( "%s\n", S );
    } else {
        // If the length of S is greater than K, return the first K characters of S followed by '...'
        printf ( "%.*s...\n", K, S );
    }
    return 0;
}
