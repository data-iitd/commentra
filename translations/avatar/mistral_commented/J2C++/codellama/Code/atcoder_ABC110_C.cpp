
#include <iostream>
#include <string>

using namespace std ;

int main ( ) {
    // Initialize a string object S to store the first input line
    string S ;

    // Initialize a string object T to store the second input line
    string T ;

    // Read the first input line from the console
    getline ( cin , S ) ;

    // Read the second input line from the console
    getline ( cin , T ) ;

    // Initialize an array of strings A with all possible characters from a to z
    string A [ ] = { "a" , "b" , "c" , "d" , "e" , "f" , "g" , "h" , "i" , "j" , "k" , "l" , "m" , "n" , "o" , "p" , "q" , "r" , "s" , "t" , "u" , "v" , "w" , "x" , "y" , "z" } ;

    // Initialize a boolean variable res to store the result of the comparison
    bool res = true ;

    // Iterate through each string s in the array A
    for ( string s : A ) {
        // Find the index of string s in string S
        int sIdx = S.find ( s ) ;

        // If string s is not found in string S, continue to the next string in the array
        if ( sIdx == string::npos ) continue ;

        // Convert the character at the index sIdx in string T to a string
        string t = string ( 1 , T [ sIdx ] ) ;

        // Initialize an index variable idx to 0
        int idx = 0 ;

        // Iterate through each character in string S starting from the index sIdx
        while ( idx < S.length ( ) ) {
            // If string s is found in string S starting from index idx, compare the corresponding characters in strings S and T
            if ( S.find ( s , idx ) != string::npos ) {
                if ( S.find ( s , idx ) != T.find ( t , idx ) ) {
                    // If the characters do not match, set the boolean variable res to false and break out of the loop
                    res = false ;
                    break ;
                } else {
                    // If the characters match, increment the index variable idx by the length of string s
                    idx = S.find ( s , idx ) + 1 ;
                }
            }

            // If string s is not found in string T starting from index idx, set the boolean variable res to false and break out of the loop
            else if ( T.find ( t , idx ) != string::npos ) {
                res = false ;
                break ;
            }

            // If string s is not found in both strings S and T starting from index idx, break out of the loop
            else break ;
        }

        // If the boolean variable res is still true after the loop, print "Yes" to the console
        if ( res ) cout << "Yes" << endl ;

        // If the boolean variable res is false, print "No" to the console and break out of the main loop
        else {
            cout << "No" << endl ;
            break ;
        }
    }

    // End of code
    return 0 ;
}

