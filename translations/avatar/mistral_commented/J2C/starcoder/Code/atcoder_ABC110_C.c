_

#include <stdio.h>
#include <string.h>

int main ( ) {
    char S [ 1000 ] = { 0 } ; // Initialize string S to store the first input line
    char T [ 1000 ] = { 0 } ; // Initialize string T to store the second input line

    scanf ( "%s", S ) ; // Read the first input line from the console

    scanf ( "%s", T ) ; // Read the second input line from the console

    int A [ 26 ] = { 0 } ; // Initialize an array of integers A with all possible characters from a to z

    for ( int i = 0 ; i < 26 ; i ++ ) {
        A [ i ] = i + 97 ; // Convert the integer i to a character and store it in the array A
    }

    bool res = true ; // Initialize a boolean variable res to store the result of the comparison

    for ( int i = 0 ; i < 26 ; i ++ ) {
        char s = A [ i ] ; // Find the character s in the array A

        int sIdx = -1 ; // Initialize an integer sIdx to store the index of string s in string S

        for ( int j = 0 ; j < strlen ( S ) ; j ++ ) {
            if ( S [ j ] == s ) {
                sIdx = j ; // If string s is found in string S, store the index of string s in string S in the integer sIdx
                break ;
            }
        }

        if ( sIdx < 0 ) continue ; // If string s is not found in string S, continue to the next string in the array

        char t = T [ sIdx ] ; // Convert the character at the index sIdx in string T to a character

        int idx = 0 ; // Initialize an integer idx to 0

        while ( idx < strlen ( S ) ) {
            if ( S [ idx ] == s ) {
                if ( S [ idx ]!= T [ idx ] ) {
                    res = false ; // If the characters do not match, set the boolean variable res to false and break out of the loop
                    break ;
                } else {
                    idx ++ ; // If the characters match, increment the index variable idx by 1
                }
            } else if ( T [ idx ] == s ) {
                res = false ; // If string s is found in string T starting from index idx, set the boolean variable res to false and break out of the loop
                break ;
            } else {
                break ; // If string s is not found in both strings S and T starting from index idx, break out of the loop
            }
        }

        if ( res ) printf ( "Yes\n" ) ; // If the boolean variable res is still true after the loop, print "Yes" to the console

        else {
            printf ( "No\n" ) ; // If the boolean variable res is false, print "No" to the console and break out of the main loop
            break ;
        }
    }

    return 0 ;
}

