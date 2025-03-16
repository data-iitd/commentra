
######
#include <bits/stdc++.h>
using namespace std;

// Method to check if a character is a Latin letter
bool isLatinLetter ( char c ) {
    // Check if the character falls within the ASCII range of Latin letters
    return c >= 'a' && c <= 'z' ;
}

// Method to check if a character is a punctuation mark
bool isPunctuation ( char c ) {
    // Check if the character is a dot, comma, exclamation mark, or question mark
    if ( c == '.' ) return true ;
    if ( c == ',' ) return true ;
    if ( c == '!' ) return true ;
    if ( c == '?' ) return true ;
    // If none of the above conditions are met, return false
    return false ;
}

int main ( ) {
    // Creating BufferedReader to read input from the console
    BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;

    // Creating PrintWriter to write output to the console
    PrintWriter pw = new PrintWriter ( System.out ) ;

    // Reading a line of input from the console
    String s = br.readLine ( ) ;

    // Creating a StringBuilder to store the output
    StringBuilder sb = new StringBuilder ( ) ;

    // Finding the length of the input string
    int n = s.length ( ) ;

    // Appending the first character of the input string to the StringBuilder
    sb.append ( s.charAt ( 0 ) ) ;

    // Iterating through the rest of the characters in the input string
    for ( int i = 1 ; i < n ; i ++ ) {
        // Getting the current character from the input string
        char c = s.charAt ( i ) ;

        // If the current character is a Latin letter, append it to the StringBuilder with a space before it if the previous character was not a Latin letter
        if ( isLatinLetter ( c ) ) {
            if (! isLatinLetter ( s.charAt ( i - 1 ) ) ) {
                sb.append ('' ) ;
            }
            sb.append ( c ) ;
        }
        // If the current character is a punctuation mark, append it directly to the StringBuilder without a space
        else if ( isPunctuation ( c ) ) {
            sb.append ( c ) ;
        }
    }

    // Writing the output to the console
    pw.println ( sb ) ;
    pw.flush ( ) ;
    pw.close ( ) ;
    return 0;
}
