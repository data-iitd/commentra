#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    char * input = NULL ;  // Declaring a pointer to a string to store the input
    char * numlist [ ] = { NULL, NULL } ;  // Declaring an array of two pointers to strings to store the first two elements of the input
    int Sheep = 0 ;  // Declaring an integer to store the number of sheep
    int Wolve = 0 ;  // Declaring an integer to store the number of wolves

    // The following for loop reads input lines from the console and stores them in the input string
    for ( int i = 0 ; i >= 0 ; i ++ ) {
        try {
            input = ( char * ) realloc ( input, ( i + 1 ) * sizeof ( char ) ) ;  // Reallocating memory for the input string
            scanf ( "%s", input + i ) ;  // Reading the next line from the console and adding it to the input string
        } catch ( Exception e ) {
            break ;  // Exiting the loop if an exception occurs during input reading
        }
    }

    // The following line extracts the first line of the input (which contains the number of sheep and wolves)
    strcpy ( numlist [ 0 ], strtok ( input, " " ) ) ;
    strcpy ( numlist [ 1 ], strtok ( NULL, " " ) ) ;

    // The following two lines parse the first two elements of the numlist array as integers representing the number of sheep and wolves
    Sheep = atoi ( numlist [ 0 ] ) ;
    Wolve = atoi ( numlist [ 1 ] ) ;

    // The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
    // If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
    if ( Wolve >= Sheep ) {
        printf ( "unsafe\n" ) ;  // Printing the message "unsafe" to the console
    } else {
        printf ( "safe\n" ) ;  // Printing the message "safe" to the console
    }

    free ( input ) ;  // Freeing the memory allocated for the input string
    free ( numlist [ 0 ] ) ;  // Freeing the memory allocated for the first element of the numlist array
    free ( numlist [ 1 ] ) ;  // Freeing the memory allocated for the second element of the numlist array

    return 0 ;  // Returning 0 to indicate successful execution
}

