
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    // Declaring and initializing variables
    long a;
    char b [ 100 ];
    int length;
    char bChar [ 100 ];
    int i;
    int bInt;
    long result;

    // Reading input from the console
    scanf ( "%ld", &a );
    scanf ( "%s", b );

    // Converting String 'b' to char array 'bChar'
    strcpy ( bChar, b );

    // Getting length of char array 'bChar'
    length = strlen ( bChar );

    // Initializing empty String variable 'bStr'
    char bStr [ 100 ];
    bStr [ 0 ] = '\0';

    // Loop to iterate through each character in char array 'bChar'
    for ( i = 0 ; i < length ; i ++ ) {
        if ( bChar [ i ] != '.' ) {
            // If current character is not '.', add it to String 'bStr'
            strcat ( bStr, &bChar [ i ] );
        }
    }

    // Converting String 'bStr' to integer and assigning it to 'bInt'
    bInt = atoi ( bStr );

    // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to 'result'
    result = ( a * bInt ) / 100;

    // Printing the value of 'result' to the console
    printf ( "%ld\n", result );

    return 0;
}

