
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int N ; // Declaring and initializing the variable N
    scanf ( "%d", &N ) ; // Reading the value of N from the user

    long i = 357 ; // Initializing the variable i with a value of 357
    int c = 0 ; // Initializing the variable c with a value of 0

    while ( i <= N ) { // Starting a while loop that continues as long as i is less than or equal to N
        char s [ 100 ] ; // Declaring and initializing a character array s with a size of 100
        scanf ( "%s", s ) ; // Reading a string from the user

        if ( strstr ( s, "3" ) && strstr ( s, "5" ) && strstr ( s, "7" ) ) { // Checking if the string contains the digits 3, 5, and 7
            c ++ ; // Incrementing the value of c by 1 if the condition is true
        }

        char sb [ 100 ] = { 0 } ; // Declaring and initializing a character array sb with a size of 100 and setting all values to 0
        int f = 0 ; // Initializing a boolean variable f with a value of 0

        for ( int j = 0 ; j < strlen ( s ) ; j ++ ) { // Starting a for loop that iterates through each character in the string s
            char a = s [ strlen ( s ) - 1 - j ] ; // Getting the character at the current index in reverse order

            if ( f ) { // If the boolean variable f is true, meaning we have found the first occurrence of 3, 5, or 7
                sb [ j ] = a ; // Appending the current character to the character array sb
            } else { // If the boolean variable f is false, meaning we have not found the first occurrence of 3, 5, or 7 yet
                if ( a == '3' ) { // Checking if the current character is a 3
                    sb [ j ] = '5' ; // If it is, append a 5 to the character array sb and set f to true
                    f = 1 ;
                } else if ( a == '5' ) { // Checking if the current character is a 5
                    sb [ j ] = '7' ; // If it is, append a 7 to the character array sb and set f to true
                    f = 1 ;
                } else { // If the current character is not a 3, 5, or 7, append a 3 to the character array sb and set f to true
                    sb [ j ] = '3' ;
                    f = 1 ;
                }
            }
        }

        if ( ! f ) sb [ 0 ] = '3' ; // If we have not found any 3, 5, or 7 in the string, append a 3 to the character array sb

        char sb2 [ 100 ] = { 0 } ; // Declaring and initializing a character array sb2 with a size of 100 and setting all values to 0
        for ( int j = 0 ; j < strlen ( sb ) ; j ++ ) { // Starting a for loop that iterates through each character in the character array sb
            sb2 [ j ] = sb [ strlen ( sb ) - 1 - j ] ; // Appending the current character to the character array sb2 in reverse order
        }

        i = atol ( sb2 ) ; // Converting the reversed string back to a long integer and assigning it to the variable i
    }

    printf ( "%d\n", c ) ; // Printing the value of c to the console

    return 0 ;
}

