
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    // Declaring the main method, which is the entry point of the C application

    char * arr = malloc ( 100 * sizeof ( char ) ) ;
    // Creating a character array 'arr' of size 100 and dynamically allocating memory for it

    scanf ( "%s" , arr ) ;
    // Reading a string as input and storing it in the 'arr' character array

    int N = strlen ( arr ) ;
    // Declaring and initializing the length of the character array 'arr' in the variable 'N'

    int K = 0 ;
    // Declaring and initializing an integer variable 'K' to store the number of input strings

    scanf ( "%d" , & K ) ;
    // Reading an integer as input and storing it in the variable 'K'

    int res = 0 ;
    // Declaring and initializing an integer variable 'res' to store the result

    for ( int k = 0 ; k < K ; k ++ ) {
        // Starting a for loop that iterates 'K' times

        char * input = malloc ( 100 * sizeof ( char ) ) ;
        // Creating a character array 'input' of size 100 and dynamically allocating memory for it

        scanf ( "%s" , input ) ;
        // Reading a string as input and storing it in the 'input' character array

        int a = 0 ;
        int b = 0 ;
        // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the character array 'arr'

        for ( int i = 0 ; i < N ; i ++ ) {
            // Starting a nested for loop that iterates through each index of the character array 'arr'

            if ( arr [ i ] == input [ 0 ] )
                a ++ ;  // Incrementing the 'a' variable if the character at the current index matches the first character of the input string

            else if ( arr [ i ] == input [ 1 ] )
                b ++ ;  // Incrementing the 'b' variable if the character at the current index matches the second character of the input string

            else {
                res += ( a < b ) ? a : b ;  // Adding the minimum of 'a' and 'b' to the 'res' variable if the current character is different from both characters in the input string
                a = b = 0 ;  // Resetting the 'a' and 'b' variables to zero
            }
        }

        res += ( a < b ) ? a : b ;  // Adding the minimum of 'a' and 'b' to the 'res' variable after the end of the outer for loop
    }

    printf ( "%d\n" , res ) ;
    // Printing the final result to the standard output stream

    free ( arr ) ;
    // Freeing the memory allocated for the 'arr' character array

    free ( input ) ;
    // Freeing the memory allocated for the 'input' character array

    return 0 ;
}

