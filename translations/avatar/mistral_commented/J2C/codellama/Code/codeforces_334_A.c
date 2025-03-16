
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ;  // Declaring the variable 'n' for the number
    int square ;  // Declaring the variable 'square' for the square of the number
    int loop ;  // Declaring the variable 'loop' for the number of pairs to be printed
    int div ;  // Declaring the variable 'div' for half of the number of pairs
    int i , j ;  // Declaring the variables 'i' and 'j' for the loop counters
    int *odd , *even ;  // Declaring the variables 'odd' and 'even' for the arrays of odd and even numbers
    int odd_size , even_size ;  // Declaring the variables 'odd_size' and 'even_size' for the sizes of the arrays
    int odd_index , even_index ;  // Declaring the variables 'odd_index' and 'even_index' for the indices of the arrays

    scanf ( "%d" , &n ) ;  // Reading the number 'n' from the user

    square = n * n ;  // Calculating the square of the number 'n'

    loop = square / n ;  // Calculating the number of pairs to be printed
    div = loop / 2 ;  // Calculating half of the number of pairs

    odd_size = ( loop + 1 ) / 2 ;  // Calculating the size of the array of odd numbers
    even_size = ( loop + 1 ) / 2 ;  // Calculating the size of the array of even numbers

    odd = ( int * ) malloc ( odd_size * sizeof ( int ) ) ;  // Allocating memory for the array of odd numbers
    even = ( int * ) malloc ( even_size * sizeof ( int ) ) ;  // Allocating memory for the array of even numbers

    for ( i = 1 ; i <= square ; i ++ ) {  // Looping from 1 to square
        if ( i % 2 == 0 ) {  // If the number is even
            even [ even_index ] = i ;  // Add the number to the even array
            even_index ++ ;  // Increment the index of the even array
        } else {  // If the number is odd
            odd [ odd_index ] = i ;  // Add the number to the odd array
            odd_index ++ ;  // Increment the index of the odd array
        }
    }

    for ( i = 1 ; i <= loop ; i ++ ) {  // Looping through each pair
        for ( j = 0 ; j < div ; j ++ ) {  // Looping through half of the pair
            if ( i % 2 == 1 ) {  // If the current pair is odd
                printf ( "%d %d " , odd [ j ] , even [ even_size - j - 1 ] ) ;  // Print the first and last numbers of the current pair
            } else {  // If the current pair is even
                printf ( "%d %d " , even [ j ] , odd [ odd_size - j - 1 ] ) ;  // Print the last and first numbers of the current pair
            }
        }
        printf ( "\n" ) ;  // Printing a newline after each pair
    }

    free ( odd ) ;  // Freeing the memory allocated for the array of odd numbers
    free ( even ) ;  // Freeing the memory allocated for the array of even numbers

    return 0 ;  // Returning 0 to indicate successful execution
}

