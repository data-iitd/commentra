
#include <stdio.h>

#include <string.h>

int main ( ) {

    int K ; // Declare an integer variable `K`

    char S [ 100 ] ; // Declare a character array `S` with 100 elements

    scanf ( "%d" , &K ) ; // Read an integer `K` from the standard input stream

    scanf ( "%s" , S ) ; // Read a string `S` from the standard input stream

    if ( strlen ( S ) <= K ) { // Check if the length of the string `S` is less than or equal to the integer `K`

        printf ( "%s" , S ) ; // If the condition is true, print the string `S` to the standard output

    } else { // If the condition is false

        printf ( "%.*s..." , K , S ) ; // Print the first `K` characters of the string `S` followed by "..." to the standard output

    }

    return 0 ; // Return 0 to indicate that the program has completed successfully

}

