#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    char str [ 100 ] ; // Declaring a character array to store the input string
    long k ; // Declaring a long integer to store the input limit
    int n ; // Declaring an integer to store the length of the input string
    int i ; // Declaring an integer to iterate through the character array

    scanf ( "%s", str ) ; // Reading the first line of input as a string
    scanf ( "%ld", &k ) ; // Reading the second line of input as a long integer
    n = strlen ( str ) ; // Finding the length of the input string

    for ( i = 0 ; i < k ; i ++ ) { // Starting a for loop to iterate through the character array up to the given limit 'k'
        if ( str [ i ] == '1' ) { // Checking if the current character is '1'
            if ( i == k - 1 ) { // Checking if the current index is the last index of the array
                printf ( "1\n" ) ; // If yes, print '1' and exit the method
                return 0 ;
            }
        } else {
            printf ( "%c\n", str [ i ] ) ; // If the current character is not '1', print it to the console
            return 0 ; // Exit the method as soon as a non-'1' character is found
        }
    }

    return 0 ;
}

