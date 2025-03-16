
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include necessary header files for input/output operations and utility methods

int main ( ) { 
    int a, b, c, d ; 
    scanf ( "%d %d %d %d" , & a , & b , & c , & d ) ; 
    
    // Read four integers from the input
    
    if ( c > b ) { 
        printf ( "0\n" ) ; 
    } else if ( a > d ) { 
        printf ( "0\n" ) ; 
    } else if ( a < c ) { 
        printf ( "%d\n" , d - c ) ; 
    } else { 
        int l [ ] = { a , b , c , d } ; 
        qsort ( l , 4 , sizeof ( int ) , cmp ) ; 
        printf ( "%d\n" , l [ 2 ] - l [ 1 ] ) ; 
    } 
    
    // Check the values of a, b, c, and d and print the result based on the conditions
    
    return 0 ; 
} 

int cmp ( const void * a , const void * b ) { 
    return ( * ( int * ) a - * ( int * ) b ) ; 
} 

// Define a comparison function for qsort

// 