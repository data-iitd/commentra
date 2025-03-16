

#include <stdio.h>

int main ( ) {
    int n, m, sa, a, b ;
    scanf ( "%d %d", &n, &m ) ;
    // Read two integers n and m from input

    sa = 0 ;
    // Initialize sa to 0

    char c ;
    while ( ( c = getchar ( ) )!= '\n' ) {
        // Read characters from input until a newline is encountered
        if ( c == '-' ) {
            sa ++ ;
            // Increment sa if the character is '-'
        }
    }

    sa = sa < n - sa? sa : n - sa ;
    // Set sa to the minimum of sa and n - sa, possibly normalizing sa

    char *ss = malloc ( m * sizeof ( char ) ) ;
    // Allocate memory for ss

    int i ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d %d", &a, &b ) ;
        // Read two integers a and b from input

        b -= a ;
        // Subtract a from b

        if ( b % 2 && b <= sa * 2 ) {
            // Check if b is odd and within certain bounds
            ss [ i ] = '1' ;
            // Assign '1' to ss[i] if condition is met
        } else {
            ss [ i ] = '0' ;
            // Assign '0' to ss[i] otherwise
        }
    }

    ss [ m ] = '\0' ;
    // Null-terminate ss

    printf ( "%s", ss ) ;
    // Print the contents of ss

    free ( ss ) ;
    // Free the memory allocated for ss

    return 0 ;
    // Return 0 to indicate successful execution
}
// End of code