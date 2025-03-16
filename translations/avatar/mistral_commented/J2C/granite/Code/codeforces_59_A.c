
#include <stdio.h>  // Include the standard input/output library
#include <string.h>  // Include the string library

int main ( void ) {  // Main function, entry point of the program
    char word [ 100 ] ;  // Declare a character array to store the input word
    fgets ( word, sizeof ( word ), stdin ) ;  // Read the input word from the console

    int uppercase = 0 ;  // Initialize a counter for uppercase characters
    int lowercase = 0 ;  // Initialize a counter for lowercase characters

    for ( int i = 0 ; i < strlen ( word ) ; i ++ ) {  // Iterate through each character in the word
        char ch = word [ i ] ;  // Assign the character at the current index to a char variable

        if ( ch >= 'A' && ch <= 'Z' ) {  // Check if the character is uppercase
            uppercase ++ ;  // Increment the uppercase counter
        } else {
            lowercase ++ ;  // Increment the lowercase counter
        }
    }

    if ( uppercase > lowercase ) {  // Check if there are more uppercase characters than lowercase characters
        printf ( "%s\n", word ) ;  // Print the word in uppercase if condition is true
    } else if ( lowercase > uppercase ) {  // Check if there are more lowercase characters than uppercase characters
        printf ( "%s\n", word ) ;  // Print the word in lowercase if condition is true
    } else {  // If both uppercase and lowercase characters are equal
        printf ( "%s\n", word ) ;  // Print the word in lowercase if both conditions are false
    }

    return 0 ;  // Return 0 to indicate successful execution of the program
}
