// Including necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the main function
int main ( ) {

    // Declaring a variable 'num' to store the number of strings
    int num ;

    // Reading the number of strings 'num' from the user input
    scanf ( "%d", &num ) ;

    // Declaring an array of strings 'arr' with a size equal to 'num'
    char arr [ num ] [ 100 ] ;

    // Reading each string 's' from the user input and storing it in the array 'arr'
    for ( int i = 0 ; i < num ; i ++ ) {
        scanf ( "%s", arr [ i ] ) ;
    }

    // Declaring two variables 'counter' and 'fine'
    int counter = 0 ;
    int fine = 0 ;

    // The first nested loop to iterate through each character in each string
    for ( int i = 0 ; i < num ; i ++ ) {
        for ( int k = 0 ; k < num ; k ++ ) {
            // Checking if the character at position (i,k) in the string at index 'i' is 'C'
            if ( arr [ i ] [ k ] == 'C' ) {
                // Incrementing the counter variable
                counter ++ ;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += ( counter * ( counter - 1 ) ) / 2 ;
        // Resetting the counter variable for the next string
        counter = 0 ;
    }

    // The second nested loop to iterate through each character in each string again
    for ( int i = 0 ; i < num ; i ++ ) {
        for ( int k = 0 ; k < num ; k ++ ) {
            // Checking if the character at position (i,k) in the string at index 'k' is 'C'
            if ( arr [ k ] [ i ] == 'C' ) {
                // Incrementing the counter variable
                counter ++ ;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += ( counter * ( counter - 1 ) ) / 2 ;
        // Resetting the counter variable for the next string
        counter = 0 ;
    }

    // Printing the final result 'fine'
    printf ( "%d\n", fine ) ;

    // Closing the main function
    return 0 ;

    // Closing the main program
}

