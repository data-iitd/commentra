
#include <stdio.h> // Include the standard input/output library

int main ( void ) { // Starting the main method
    char n [ 100 ] ; // Declaring a character array 'n' with a maximum length of 100 characters
    fgets ( n, 100, stdin ) ; // Reading a string from the console and storing it in the character array 'n'

    bool s = false ; // Initializing a boolean variable's' to false

    for ( int i = 0 ; n [ i ]!= '\0' ; i ++ ) { // Starting a for loop to iterate through each character in the character array 'n'
        if ( n [ i ] == '.' ) { // Checking if the current character is a '.'
            if ( s ) { // If the boolean variable's' is true
                printf ( "1" ) ; // Printing '1' to the console
                s = false ; // Setting the boolean variable's' to false
            } else { // If the boolean variable's' is false
                printf ( "0" ) ; // Printing '0' to the console
            }
        } else { // If the current character is not a '.'
            if ( s ) { // If the boolean variable's' is true
                printf ( "2" ) ; // Printing '2' to the console
                s = false ; // Setting the boolean variable's' to false
            } else { // If the boolean variable's' is false
                s = true ; // Setting the boolean variable's' to true
            }
        }
    }

    return 0 ; // Returning 0 to indicate successful execution of the program
}

