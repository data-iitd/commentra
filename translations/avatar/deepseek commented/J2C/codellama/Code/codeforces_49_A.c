#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( ) { 
    char s [ 100 ] ; // Declare a character array s to store the input string
    int length = 0 ; // Declare an integer variable length to store the length of the string s
    char ch = 0 ; // Declare a character variable ch to store the last non-space character in the string s

    // Read a line of input from the user and store it in the character array s
    fgets ( s , 100 , stdin ) ; 

    // Calculate the length of the string s
    length = strlen ( s ) ; 

    // Iterate through the string s in reverse order, starting from the last character
    for ( int i = length - 1 ; i >= 0 ; i -- ) { 
        if ( s [ i ] != ' ' && s [ i ] != '?' ) { // Check if the current character is not a space or a question mark
            ch = s [ i ] ; // Assign the current character to the variable ch
            break ; // Exit the loop
        } 
    }

    ch = tolower ( ch ) ; // Convert the character ch to lowercase

    // Check if ch is one of the vowels (a, e, i, o, u, y)
    if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ) { 
        printf ( "YES\n" ) ; // Print "YES" if ch is a vowel
    } else { 
        printf ( "NO\n" ) ; // Print "NO" if ch is not a vowel
    } 

    return 0 ; // Return 0 to indicate that the program executed successfully
}

