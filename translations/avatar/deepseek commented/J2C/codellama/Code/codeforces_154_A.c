
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    // Reading input from standard input
    char *input = malloc ( 1000000 * sizeof ( char ) ) ;
    scanf ( "%s", input ) ;
    int N = strlen ( input ) ;

    // Initialize a HashSet to store unique strings and read the number of test cases
    int K ;
    scanf ( "%d", &K ) ;

    // Initialize the result variable to store the final count
    int res = 0 ;

    // Loop to process each test case
    for ( int k = 0 ; k < K ; k ++ ) {
        char *input = malloc ( 1000000 * sizeof ( char ) ) ;
        scanf ( "%s", input ) ;
        int a = 0 ;
        int b = 0 ;

        // Iterate over the characters of the input array
        for ( int i = 0 ; i < N ; i ++ ) {
            if ( input [ i ] == input [ 0 ] ) // If the character matches the first character of the input
                a ++ ;
            else if ( input [ i ] == input [ 1 ] ) // If the character matches the second character of the input
                b ++ ;
            else { // If the character does not match either of the input characters
                res += ( a < b ) ? a : b ; // Add the minimum of a and b to the result
                a = b = 0 ; // Reset the counters
            }
        }
        res += ( a < b ) ? a : b ; // Add the minimum of a and b to the result after the loop
    }

    // Print the final result
    printf ( "%d\n", res ) ;

    return 0 ;
}

