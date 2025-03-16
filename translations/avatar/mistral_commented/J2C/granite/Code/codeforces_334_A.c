

#include <stdio.h>  // Include required header files for input and output
#include <stdlib.h>
#include <string.h>

int main ( ) {
     // Initializing variables for input and output
    int n ;  // Declaring variable 'n' to store the number from the user
    scanf ( "%d", &n ) ;  // Reading the number 'n' from the user using scanf

    int square = n * n ;  // Calculating the square of the number 'n'

    int *odd = ( int * ) malloc ( sizeof ( int ) * square ) ;  // Dynamically allocating memory for the odd numbers
    int *even = ( int * ) malloc ( sizeof ( int ) * square ) ;  // Dynamically allocating memory for the even numbers

    int i, j ;  // Declaring variables for loop control

    for ( i = 1 ; i <= square ; i ++ ) {  // Looping from 1 to square
        if ( i % 2 == 0 ) {  // If the number is even
            even [ i - 1 ] = i ;  // Store the even number in the even array
        } else {  // If the number is odd
            odd [ i - 1 ] = i ;  // Store the odd number in the odd array
        }
    }

    int loop = square / n ;  // Calculating the number of pairs to be printed
    int div = loop / 2 ;  // Calculating half of the number of pairs

    for ( i = 1 ; i <= loop ; i ++ ) {  // Looping through each pair
        for ( j = 0 ; j < div ; j ++ ) {  // Looping through half of the pair
            if ( i % 2 == 1 ) {  // If the current pair is odd
                printf ( "%d %d ", odd [ 0 ], even [ square - 1 ] ) ;  // Print the first and last numbers of the current pair
                odd [ 0 ] ++ ;  // Increment the first number of the current pair
                even [ square - 1 ] -- ;  // Decrement the last number of the current pair
            } else {  // If the current pair is even
                printf ( "%d %d ", even [ 0 ], odd [ square - 1 ] ) ;  // Print the last and first numbers of the current pair
                even [ 0 ] ++ ;  // Increment the first number of the current pair
                odd [ square - 1 ] -- ;  // Decrement the last number of the current pair
            }
        }
        printf ( "\n" ) ;  // Printing a newline after each pair
    }

    free ( odd ) ;  // Freeing the memory allocated for the odd array
    free ( even ) ;  // Freeing the memory allocated for the even array

    return 0 ;  // Returning 0 to indicate successful execution
}

Translate the above C code to Python and end with comment "