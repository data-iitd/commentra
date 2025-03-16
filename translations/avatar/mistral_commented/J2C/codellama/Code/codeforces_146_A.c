
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    int x = 0 , y = 0 ;  // Declaring and initializing two integer variables x and y
    int t = 0 ;  // Declaring and initializing an integer variable t
    int n = 0 ;  // Declaring and initializing an integer variable n to store the length of the input string
    
    char str [ ] = { '\0' } ;  // Declaring and initializing an empty character array str to store the input string
    char l [ ] = { '\0' } ;  // Declaring and initializing a character array l of size equal to the length of the input string
    
    scanf ( "%d" , &n ) ;  // Reading the integer value of n from the standard input
    scanf ( "%s" , str ) ;  // Reading the string value of the input from the standard input
    
    l = ( char * ) malloc ( sizeof ( char ) * ( strlen ( str ) + 1 ) ) ;  // Creating a character array l of size equal to the length of the input string and assigning it the value of the input string using strcpy() function
    strcpy ( l , str ) ;
    
    for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through each character in the input string
        if ( l [ i ] != '4' && l [ i ] != '7' ) {  // Checking if the current character is not equal to '4' or '7'
            t = 1 ;  // Setting the value of t to 1 if the condition is true
        }
    }
    
    if ( t == 1 ) {  // Checking if the value of t is equal to 1
        printf ( "NO" ) ;  // Printing "NO" if the condition is true
    } else {  // Else part of the if statement
        int sumX = 0 ;  // Declaring and initializing an integer variable sumX to store the sum of the digits in the first half of the string
        int sumY = 0 ;  // Declaring and initializing an integer variable sumY to store the sum of the digits in the second half of the string
        
        for ( int i = 0 ; i < n / 2 ; i ++ ) {  // Iterating through the first half of the string to calculate the sum of its digits
            x = x + l [ i ] - '0' ;  // Adding the value of the current digit to the variable x
        }
        
        for ( int i = n - 1 ; i > ( n / 2 ) - 1 ; i -- ) {  // Iterating through the second half of the string to calculate the sum of its digits
            y = y + l [ i ] - '0' ;  // Adding the value of the current digit to the variable y
        }
        
        if ( x == y ) {  // Checking if the sum of digits in the first half is equal to the sum of digits in the second half
            printf ( "YES" ) ;  // Printing "YES" if the condition is true
        } else {  // Else part of the if statement
            printf ( "NO" ) ;  // Printing "NO" if the condition is false
        }
    }
    
    return 0 ;  // Returning 0 to indicate that the program executed successfully
}

