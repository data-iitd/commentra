
#include <stdio.h>
#include <string.h>

int main ( ) {
    // Initialize a string S to store the first input line
    char S [ 100 ] = { '\0' } ;

    // Initialize a string T to store the second input line
    char T [ 100 ] = { '\0' } ;

    // Read the first input line from the console
    scanf ( "%s" , S ) ;

    // Read the second input line from the console
    scanf ( "%s" , T ) ;

    // Initialize an array of strings A with all possible characters from a to z
    char A [ 26 ] [ 2 ] = { "a" , "b" , "c" , "d" , "e" , "f" , "g" , "h" , "i" , "j" , "k" , "l" , "m" , "n" , "o" , "p" , "q" , "r" , "s" , "t" , "u" , "v" , "w" , "x" , "y" , "z" } ;

    // Initialize a boolean variable res to store the result of the comparison
    int res = 1 ;

    // Iterate through each string s in the array A
    for ( int i = 0 ; i < 26 ; i++ ) {
        // Find the index of string s in string S
        int sIdx = strstr ( S , A [ i ] ) - S ;

        // If string s is not found in string S, continue to the next string in the array
        if ( sIdx < 0 ) continue ;

        // Convert the character at the index sIdx in string T to a string
        char t [ 2 ] = { T [ sIdx ] , '\0' } ;

        // Initialize an index variable idx to 0
        int idx = 0 ;

        // Iterate through each character in string S starting from the index sIdx
        while ( idx < strlen ( S ) ) {
            // If string s is found in string S starting from index idx, compare the corresponding characters in strings S and T
            if ( strstr ( S , A [ i ] , idx ) != NULL ) {
                if ( strstr ( S , A [ i ] , idx ) != strstr ( T , t , idx ) ) {
                    // If the characters do not match, set the boolean variable res to false and break out of the loop
                    res = 0 ;
                    break ;
                } else {
                    // If the characters match, increment the index variable idx by the length of string s
                    idx = strstr ( S , A [ i ] , idx ) - S + 1 ;
                }
            }

            // If string s is not found in string T starting from index idx, set the boolean variable res to false and break out of the loop
            else if ( strstr ( T , t , idx ) != NULL ) {
                res = 0 ;
                break ;
            }

            // If string s is not found in both strings S and T starting from index idx, break out of the loop
            else break ;
        }

        // If the boolean variable res is still true after the loop, print "Yes" to the console
        if ( res ) printf ( "Yes\n" ) ;

        // If the boolean variable res is false, print "No" to the console and break out of the main loop
        else {
            printf ( "No\n" ) ;
            break ;
        }
    }

    // End of code
    printf ( "