
#include <stdio.h>
#include <string.h>

int main ( ) {
    // Declare variables
    int K ;
    char S [ 100 ] ;
    
    // Read input from the user
    scanf ( "%d" , &K ) ;
    scanf ( "%s" , S ) ;
    
    // Check if the length of the string S is less than or equal to K
    if ( strlen ( S ) <= K ) {
        // If true, print the string S as it is
        printf ( "%s\n" , S ) ;
    } else {
        // If false, truncate the string to the first K characters and append "..."
        printf ( "%.*s...\n" , K , S ) ;
    }
    
    // End of code
    return 0 ;
}

