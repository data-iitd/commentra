
#####
// Importing necessary C libraries
#####
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#####
// Main method is the entry point of the C application
#####
int main ( ) {

    // Creating a character array to store the first line of input
    char str [ 100 ] ;

    // Reading the first line of input and storing it in the character array
    fgets ( str, 100, stdin ) ;

    // Creating a character array to store the second line of input
    char u [ 100 ] ;

    // Reading the second line of input and storing it in the character array
    fgets ( u, 100, stdin ) ;

    // Creating a character array to store the third line of input
    char v [ 100 ] ;

    // Reading the third line of input and storing it in the character array
    fgets ( v, 100, stdin ) ;

    // Creating a character pointer to store the first string from the first line of input
    char *token = strtok ( str, " " ) ;

    // Creating a character pointer to store the third line of input
    char *ptr = strstr ( u, token ) ;

    // Checking if the first string from the first line matches with the given string 'u'
    if ( ptr!= NULL ) {

        // If the condition is true, then print the result as (a-1) and b
        printf ( " %d %d", ( atoi ( token ) - 1 ), atoi ( v ) ) ;

    } else {

        // If the condition is false, then print the result as a and (b-1)
        printf ( " %d %d", atoi ( token ), ( atoi ( v ) - 1 ) ) ;
    }

    // Returning 0 to indicate successful execution of the C application
    return 0 ;
}
