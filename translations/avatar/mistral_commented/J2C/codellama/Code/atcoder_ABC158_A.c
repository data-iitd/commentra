
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    // Main method to start the program

    char s[100] ; // Declare a string to store the input
    scanf ( "%s" , s ) ; // Read the input string

    // Check if the string contains both 'A' and 'B'
    if ( strstr ( s , "A" ) && strstr ( s , "B" ) ) {
        printf ( "Yes\n" ) ; // Print "Yes" if both characters are present
    } else {
        printf ( "No\n" ) ; // Print "No" if either character is missing
    }

    return 0 ; // Return 0 to indicate successful execution
}

