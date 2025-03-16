
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int n ;  // Number of elements in the array
    int *array ;  // Pointer to an integer array
    int head ;  // Index of the last element to be considered in the current iteration
    long res ;  // Result variable to store the sum of the last two elements in each subarray

    // Reading the number of elements in the array from the standard input
    scanf ( "%d", &n ) ;

    // Allocating memory for the integer array
    array = ( int * ) malloc ( 3 * n * sizeof ( int ) ) ;

    // Initializing the array with input values
    for ( int i = 0 ; i < 3 * n ; i ++ )
        scanf ( "%d", &array [ i ] ) ;

    // Sorting the array in ascending order
    qsort ( array, 3 * n, sizeof ( int ), compare ) ;

    head = 3 * n - 2 ;  // Index of the last element to be considered in the current iteration
    res = 0 ;  // Initializing the result variable to 0

    // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for ( int i = 0 ; i < n ; i ++ ) {
        res += array [ head ] ;  // Adding the last element of the current subarray to the result
        head -= 2 ;  // Decreasing the index of the last element by 2 to consider the next subarray
    }

    // Printing the result
    printf ( "%ld\n", res ) ;

    // Freeing the memory allocated for the integer array
    free ( array ) ;

    return 0 ;
}

int compare ( const void *a, const void *b ) {
    return ( *( int * ) a - *( int * ) b ) ;
}

