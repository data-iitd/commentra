
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000000000

int main ( ) {
    int n ;  // Declaring a variable to store the number of elements in the array
    long a [ ] ;  // Declaring an array to store the elements
    long dp [ ] ;  // Declaring an array to store the maximum subarray sum ending at each index
    long i , j ;  // Declaring variables to store the indices of the arrays
    long max ;  // Declaring a variable to store the maximum subarray sum

    scanf ( "%d" , &n ) ;  // Reading the number of elements in the array
    a = ( long * ) malloc ( n * sizeof ( long ) ) ;  // Allocating memory for the array
    dp = ( long * ) malloc ( n * sizeof ( long ) ) ;  // Allocating memory for the dp array

    for ( i = 0 ; i < n ; i ++ ) {  // Loop to read the elements of the array from the input
        scanf ( "%ld" , &a [ i ] ) ;
    }

    dp [ n - 1 ] = a [ n - 1 ] ;  // Setting the last element of the dp array with the last element of the array

    for ( i = n - 1 ; i >= 0 ; i -- ) {  // Loop to calculate the maximum subarray sum ending at each index
        dp [ i ] = max ( dp [ i + 1 ] , a [ i ] ) ;
    }

    for ( i = 0 ; i < n ; i ++ ) {  // Loop to print the answer for each test case
        if ( a [ i ] > dp [ i + 1 ] ) {  // If the current element is greater than the maximum subarray sum ending at next index
            printf ( "0 " ) ;  // Print 0 as the answer
        } else {
            printf ( ( dp [ i + 1 ] - a [ i ] + 1 ) + " " ) ;  // Else print the length of the subarray ending at current index
        }
    }

    printf ( "\n" ) ;  // Printing a newline character at the end of the output

    free ( a ) ;  // Freeing the memory allocated for the array
    free ( dp ) ;  // Freeing the memory allocated for the dp array

    return 0 ;  // Returning 0 to indicate successful execution
}

