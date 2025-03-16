

#include <stdio.h>

int main ( ) {
    int a, b, c = 0 ;
    // Declaring and initializing variables `a`, `b`, and `c`
    scanf ( "%d %d", & a, & b ) ;
    // Reading two integer inputs, `a` and `b`, from the user
    for ( int i = 0 ; i < 2 ; i ++ ) {
        // The loop runs twice
        c += ( a > b )? a : b ;
        // Adding the maximum of `a` and `b` to `c`
        if ( a > b ) {
            // Checking if `a` is greater than `b`
            a -- ;
            // Decrementing `a` by 1 if the condition is true
        } else {
            b -- ;
            // Decrementing `b` by 1 if the condition is false
        }
    }
    printf ( "%d", c ) ;
    // Printing the value of `c` after the loop completes
    return 0 ;
}
// End of C code