#include <stdio.h>
#include <string.h>

int main ( ) {
    // Define a list containing all the vowels in upper and lower case
    char vo [ ] = { 'a' , 'e' , 'i' , 'o' , 'u' , 'y' , 'A' , 'E' , 'I' , 'O' , 'U' , 'Y' };

    // Take an input string 'a' from the user
    char a [ 100 ];
    scanf ( "%s" , a );

    // Iterate through the string 'a' from the end to the beginning
    for ( int i = strlen ( a ) - 1 ; i >= 0 ; i-- ) {
        // If the current character is a space or a question mark, skip it and move on to the next character
        if ( a [ i ] == ' ' or a [ i ] == '?' ) {
            continue;
        }
        // If the current character is not a space or a question mark, check if it is a vowel or not
        else {
            // Check if the current character is a vowel
            if ( a [ i ] in vo ) {
                // If it is, print "YES" and break out of the loop
                printf ( "YES\n" );
                break;
            }
            // If it is not, print "NO" and break out of the loop
            else {
                printf ( "NO\n" );
                break;
            }
        }
    }

    return 0;
}

