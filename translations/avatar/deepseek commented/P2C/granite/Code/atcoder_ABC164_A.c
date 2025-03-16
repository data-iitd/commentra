
#include <stdio.h>
int main ( ) {
    // Read the values of S and W from a single line of input
    int S, W ;
    scanf ( "%d %d", & S, & W ) ;
    // Check if the value of W is greater than or equal to S
    // If true, print "unsafe"
    printf ( "unsafe\n" ) ; if ( S <= W ) printf ( "safe\n" ) ;
    // Ensure the main function is called only when the script is executed directly
    return 0 ;
}
// END-OF-CODE