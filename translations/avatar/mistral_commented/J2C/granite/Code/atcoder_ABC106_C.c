
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library

int main ( void ) { // Define the main function
    char str [ 1000001 ] ; // Declare a character array to store the input String
    long k ; // Declare a long integer variable to store the input limit 'k'
    int n ; // Declare an integer variable to store the length of the String

    scanf ( "%s", str ) ; // Read the first line of input as a String and store it in the'str' array
    scanf ( "%ld", & k ) ; // Read the second line of input as a long integer and store it in the 'k' variable
    n = strlen ( str ) ; // Find the length of the String and store it in the 'n' variable

    for ( int i = 0 ; i < k ; i ++ ) { // Start a for loop to iterate through the'str' array up to the given limit 'k'
        if ( str [ i ] == '1' ) { // Check if the current character is '1'
            if ( i == k - 1 ) { // Check if the current index is the last index of the array
                printf ( "1\n" ) ; // If yes, print '1' and exit the function
                return 0 ; // Return 0 to indicate successful execution
            }
        } else {
            printf ( "%c", str [ i ] ) ; // If the current character is not '1', print it to the console
            return 0 ; // Return 0 to indicate successful execution
        }
    }
}
