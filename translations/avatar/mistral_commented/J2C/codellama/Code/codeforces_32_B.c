#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main ( ) {
    char n [ ] = { 0 } ; // Initializing a character array 'n' to store the input string
    bool s = false ; // Initializing a boolean variable 's' to false

    printf ( "Enter a string: " ) ; // Prompting the user to enter a string
    scanf ( "%s", n ) ; // Reading a string from the console and storing it in the character array 'n'

    for ( int i = 0 ; n [ i ] != '\0' ; i ++ ) { // Starting a for loop to iterate through each character in the character array 'n'
        if ( n [ i ] == '.' ) { // Checking if the current character is a '.'
            if ( s ) { // If the boolean variable 's' is true
                printf ( "1" ) ; // Printing '1' to the console
                s = false ; // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                printf ( "0" ) ; // Printing '0' to the console
            }
        } else { // If the current character is not a '.'
            if ( s ) { // If the boolean variable 's' is true
                printf ( "2" ) ; // Printing '2' to the console
                s = false ; // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                s = true ; // Setting the boolean variable 's' to true
            }
        }
    }

    printf ( "