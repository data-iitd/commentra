#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

// Constructor to initialize the superclass with System.out and auto-flush enabled
Main ( ) { 
    super ( stdout , 1 ) ; 
} 

// Scanner object to read input from System.in
Scanner sc = new Scanner ( stdin ) ; 

// Main method which is overridden and calls another main method within the class
int main ( int argc , char * argv [ ] ) { 
    Main o = new Main ( ) ; 
    o.main ( ) ; 
    o.flush ( ) ; 
    return 0 ; 
} 

// Compares two character arrays up to a specified length, ignoring case
int compare ( char * aa , int i , char * bb , int j , int m ) { 
    while ( m -- > 0 ) { 
        char a = toupper ( aa [ i ] ) ; 
        char b = toupper ( bb [ j ] ) ; 
        if ( a != b ) return a - b ; 
        i ++ ; 
        j ++ ; 
    } 
    return 0 ; 
} 

// Main logic of the program
void main ( ) { 
    // Reading the number of strings and the array of strings
    int n = sc.nextInt ( ) ; 
    char * [ ] ss = ( char * [ ] ) malloc ( n * sizeof ( char * ) ) ; 
    for ( int i = 0 ; i < n ; i ++ ) 
        ss [ i ] = sc.next ( ) ; 

    // Reading the pattern array and the target character
    char * cc = sc.next ( ) ; 
    int m = strlen ( cc ) ; 
    char c = sc.next ( ) [ 0 ] ; 
    char c_ = toupper ( c ) ; 
    char a = c == 'a' ? 'b' : 'a' ; 
    char a_ = toupper ( a ) ; 

    // Array to mark positions in cc that match any string in ss
    int [ ] lucky = ( int [ ] ) malloc ( m * sizeof ( int ) ) ; 

    // Finding lucky positions and updating characters based on the target character c
    for ( int j = 0 ; j < m ; j ++ ) 
        for ( int i = 0 ; i < n ; i ++ ) { 
            int l = strlen ( ss [ i ] ) ; 
            if ( m - j >= l && compare ( cc , j , ss [ i ] , 0 , l ) == 0 ) 
                for ( int h = 0 ; h < l ; h ++ ) 
                    lucky [ j + h ] = 1 ; 
        } 

    // Updating characters in cc based on the lucky positions and target character c
    for ( int j = 0 ; j < m ; j ++ ) 
        if ( lucky [ j ] ) { 
            if ( tolower ( cc [ j ] ) == c ) 
                cc [ j ] = isupper ( cc [ j ] ) ? a_ : a ; 
            else 
                cc [ j ] = isupper ( cc [ j ] ) ? c_ : c ; 
        } 

    // Printing the modified cc array
    printf ( "%s\n" , cc ) ; 
} 

