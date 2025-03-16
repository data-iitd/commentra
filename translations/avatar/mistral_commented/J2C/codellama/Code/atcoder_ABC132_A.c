
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    char s [ 100 ] ; // Declaring a character array to store the input string
    int i , j , k , l , m , n , o , p , q , r , t , u , v , w , x , y , z ; // Declaring variables to store the frequency of each character
    int flag = 0 ; // Declaring a variable to check if all characters have frequency 2 or not

    printf ( "Enter a string: " ) ; // Prompting the user to enter a string
    scanf ( "%s" , s ) ; // Reading a string input from the user

    for ( i = 0 ; s [ i ] != '\0' ; i ++ ) { // Iterating through each character in the string
        if ( s [ i ] == 'a' ) { // Checking if the current character is 'a'
            a ++ ; // Incrementing the frequency of 'a'
        } else if ( s [ i ] == 'b' ) { // Checking if the current character is 'b'
            b ++ ; // Incrementing the frequency of 'b'
        } else if ( s [ i ] == 'c' ) { // Checking if the current character is 'c'
            c ++ ; // Incrementing the frequency of 'c'
        } else if ( s [ i ] == 'd' ) { // Checking if the current character is 'd'
            d ++ ; // Incrementing the frequency of 'd'
        } else if ( s [ i ] == 'e' ) { // Checking if the current character is 'e'
            e ++ ; // Incrementing the frequency of 'e'
        } else if ( s [ i ] == 'f' ) { // Checking if the current character is 'f'
            f ++ ; // Incrementing the frequency of 'f'
        } else if ( s [ i ] == 'g' ) { // Checking if the current character is 'g'
            g ++ ; // Incrementing the frequency of 'g'
        } else if ( s [ i ] == 'h' ) { // Checking if the current character is 'h'
            h ++ ; // Incrementing the frequency of 'h'
        } else if ( s [ i ] == 'i' ) { // Checking if the current character is 'i'
            i ++ ; // Incrementing the frequency of 'i'
        } else if ( s [ i ] == 'j' ) { // Checking if the current character is 'j'
            j ++ ; // Incrementing the frequency of 'j'
        } else if ( s [ i ] == 'k' ) { // Checking if the current character is 'k'
            k ++ ; // Incrementing the frequency of 'k'
        } else if ( s [ i ] == 'l' ) { // Checking if the current character is 'l'
            l ++ ; // Incrementing the frequency of 'l'
        } else if ( s [ i ] == 'm' ) { // Checking if the current character is 'm'
            m ++ ; // Incrementing the frequency of 'm'
        } else if ( s [ i ] == 'n' ) { // Checking if the current character is 'n'
            n ++ ; // Incrementing the frequency of 'n'
        } else if ( s [ i ] == 'o' ) { // Checking if the current character is 'o'
            o ++ ; // Incrementing the frequency of 'o'
        } else if ( s [ i ] == 'p' ) { // Checking if the current character is 'p'
            p ++ ; // Incrementing the frequency of 'p'
        } else if ( s [ i ] == 'q' ) { // Checking if the current character is 'q'
            q ++ ; // Incrementing the frequency of 'q'
        } else if ( s [ i ] == 'r' ) { // Checking if the current character is 'r'
            r ++ ; // Incrementing the frequency of 'r'
        } else if ( s [ i ] == 's' ) { // Checking if the current character is 's'
            s ++ ; // Incrementing the frequency of 's'
        } else if ( s [ i ] == 't' ) { // Checking if the current character is 't'
            t ++ ; // Incrementing the frequency of 't'
        } else if ( s [ i ] == 'u' ) { // Checking if the current character is 'u'
            u ++ ; // Incrementing the frequency of 'u'
        } else if ( s [ i ] == 'v' ) { // Checking if the current character is 'v'
            v ++ ; // Incrementing the frequency of 'v'
        } else if ( s [ i ] == 'w' ) { // Checking if the current character is 'w'
            w ++ ; // Incrementing the frequency of 'w'
        } else if ( s [ i ] == 'x' ) { // Checking if the current character is 'x'
            x ++ ; // Incrementing the frequency of 'x'
        } else if ( s [ i ] == 'y' ) { // Checking if the current character is 'y'
            y ++ ; // Incrementing the frequency of 'y'
        } else if ( s [ i ] == 'z' ) { // Checking if the current character is 'z'
            z ++ ; // Incrementing the frequency of 'z'
        }
    }

    if ( a == 2 && b == 2 && c == 2 && d == 2 && e == 2 && f == 2 && g == 2 && h == 2 && i == 2 && j == 2 && k == 2 && l == 2 && m == 2 && n == 2 && o == 2 && p == 2 && q == 2 && r == 2 && s == 2 && t == 2 && u == 2 && v == 2 && w == 2 && x == 2 && y == 2 && z == 2 ) { // Checking if all characters have frequency 2
        printf ( "Yes" ) ; // Printing "Yes" if all characters have frequency 2
    } else {
        printf ( "No" ) ; // Printing "No" if any character has frequency other than 2
    }

    return 0 ; // Returning 0 to indicate successful execution
}

