

#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library

int main ( void ) {
    // Initializing variables
    long a;
    char b [ 1000 ] ;
    int length, i ;
    char bStr [ 1000 ] ;
    int bInt ;
    long result ;

    // Reading input from the console
    scanf ( "%ld", & a ) ;
    scanf ( "%s", b ) ;

    // Converting String 'b' to char array 'bChar'
    length = strlen ( b ) ;
    for ( i = 0 ; i < length ; i ++ ) {
        // Loop to iterate through each character in String 'b'
        if ( b [ i ]!= '.' ) {
            // If current character is not '.', add it to String 'bStr'
            bStr [ i ] = b [ i ] ;
        }
    }

    // Converting String 'bStr' to integer and assigning it to 'bInt'
    bInt = atoi ( bStr ) ;

    // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to'result'
    result = ( a * bInt ) / 100 ;

    // Printing the value of'result' to the console
    printf ( "%ld", result ) ;

    return 0 ; // Returning 0 to indicate successful execution of the program
}

