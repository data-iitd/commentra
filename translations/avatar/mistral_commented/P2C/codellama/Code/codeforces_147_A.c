#include <stdio.h>
#include <string.h>

int main ( ) {

    // Take user input as a string 's'
    char s [ 1000 ];
    scanf ( "%s" , s );

    // Initialize an empty list 'res' to store the final result
    char res [ 1000 ] = { '\0' };

    // Define a list 'punctuation' containing all the punctuation marks
    char punctuation [ ] = { ',' , '.' , '!' , '?' };

    // Iterate through each character 'i' in the string 's'
    for ( int i = 0 ; s [ i ] != '\0' ; i ++ ) {

        // If current character is a space and previous character is not empty,
        // append the space to the result list
        if ( i >= 1 ) {
            if ( res [ i - 1 ] != '\0' ) {
                // Append space to the result list
                strcat ( res , " " );
            }
        }

        // If current character is not a space and is a punctuation mark,
        // check if the previous character is empty, if yes then pop the last character from the result list
        // and append the current punctuation mark along with an empty string
        else if ( strchr ( punctuation , s [ i ] ) != NULL ) {
            if ( res [ i - 1 ] == '\0' ) {
                res [ strlen ( res ) - 1 ] = '\0';
                strcat ( res , s [ i ] );
                strcat ( res , "" );
            }
            else {
                strcat ( res , s [ i ] );
            }
        }

        // If current character is not a space and is not a punctuation mark,
        // simply append it to the result list
        else {
            strcat ( res , s [ i ] );
        }
    }

    // Join all the elements of the result list and print the final string
    printf ( "%s" , res );

    return 0;
}

