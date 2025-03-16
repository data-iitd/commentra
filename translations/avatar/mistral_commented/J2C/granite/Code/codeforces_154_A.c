
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // Declaring the main method, which is the entry point of the C application

    char arr [ 100001 ] ;
    // Declaring a character array 'arr' with a maximum length of 100001 to store the input string

    fgets ( arr, 100001, stdin ) ;
    // Reading the first line of input as a string and storing it in the 'arr' variable

    int N = strlen ( arr ) ;
    // Declaring and initializing the length of the string 'arr' in the variable 'N'

    int K ;
    scanf ( "%d", & K ) ;
    // Reading the second line of input as an integer and storing it in the variable 'K'

    int res = 0 ;
    // Declaring and initializing an integer variable'res' to store the result

    for ( int k = 0 ; k < K ; k ++ ) {
        // Starting a for loop that iterates 'K' times

        char input [ 3 ] ;
        scanf ( "%s", input ) ;
        // Reading a string as input and storing it in the 'input' variable

        int a = 0 ;
        int b = 0 ;
        // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string 'arr'

        for ( int i = 0 ; i < N ; i ++ ) {
            // Starting a nested for loop that iterates through each character in the string 'arr'

            if ( arr [ i ] == input [ 0 ] )
                a ++ ;  // Incrementing the 'a' variable if the character at the current index matches the first character of the input string

            else if ( arr [ i ] == input [ 1 ] )
                b ++ ;  // Incrementing the 'b' variable if the character at the current index matches the second character of the input string

            else {
                res += fmin ( a, b ) ;  // Adding the minimum of 'a' and 'b' to the'res' variable if the current character is different from both characters in the input string
                a = b = 0 ;  // Resetting the 'a' and 'b' variables to zero
            }
        }

        res += fmin ( a, b ) ;  // Adding the minimum of 'a' and 'b' to the'res' variable after the end of the outer for loop
    }

    printf ( "%d", res ) ;
    // Printing the final result to the standard output stream

    return 0;
    // Returning 0 to indicate successful execution of the C program
}

