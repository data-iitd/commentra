
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void cout ( char *str ) { 
    printf ( "%s\n" , str ) ; 
} 

int main ( ) { 
    int n ; 
    char str [ 100 ] , a [ 100 ] , b [ 100 ] ; 
    
    // Reading the integer input n
    scanf ( "%d" , &n ) ; 
    getchar ( ) ; 
    
    // Reading the string input str
    scanf ( "%[^\n]" , str ) ; 
    
    // Constructing the string a by taking the first n/2 characters of str
    for ( int i = 0 ; i < n / 2 ; i ++ ) { 
        a [ i ] = str [ i ] ; 
    } 
    
    // Checking if str is equal to a + a and printing the result
    if ( strcmp ( str , a ) == 0 ) 
        cout ( "Yes" ) ; 
    else 
        cout ( "No" ) ; 
    
    return 0 ; 
} 

