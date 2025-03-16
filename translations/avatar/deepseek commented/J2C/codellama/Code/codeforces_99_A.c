
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) { 
    // Read input string from the user
    char str [ 100 ] ; 
    scanf ( "%s", str ) ; 

    // Find the index of the dot ('.') in the string
    int dotIndex = 0 ; 
    for ( int i = 0 ; i < strlen ( str ) ; i ++ ) 
        if ( str [ i ] == '.' ) { 
            dotIndex = i ; 
            break ; 
        } 

    // Check if the character before the dot is '9'
    if ( str [ dotIndex - 1 ] == '9' ) { 
        printf ( "GOTO Vasilisa.\n" ) ; 
    } 
    // If the character before the dot is not '9', check the digit after the dot
    else if ( str [ dotIndex + 1 ] - '0' > 4 ) { 
        // Increment the number before the dot by 1 and print the result
        char _str [ 100 ] ; 
        for ( int i = 0 ; i < dotIndex ; i ++ ) 
            _str [ i ] = str [ i ] ; 
        printf ( "%d\n", atoi ( _str ) + 1 ) ; 
    } 
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else { 
        for ( int i = 0 ; i < dotIndex ; i ++ ) 
            printf ( "%c", str [ i ] ) ; 
        printf ( "\n" ) ; 
    } 

    return 0 ; 
}

