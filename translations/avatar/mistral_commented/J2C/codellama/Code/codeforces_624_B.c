
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n ; // Declaring a variable to store the number of elements in the array
    scanf ( "%d", &n ) ; // Reading the number of elements in the array from the user

    // Allocating memory for the array and initializing it with user input
    long int *ans = ( long int * ) malloc ( n * sizeof ( long int ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%ld", &ans [ i ] ) ; // Reading each element of the array one by one
    }

    // Sorting the array in ascending order
    qsort ( ans, n, sizeof ( long int ), compare ) ;

    // Initializing a variable to keep track of the count
    long int count = ans [ n - 1 ] ; // The last element of the sorted array is the maximum element

    // Iterating through the array from the second last element to the first
    for ( int i = n - 2 ; i >= 0 ; i -- ) {
        // If the current element is less than the next element, add it to the count
        if ( ans [ i ] < ans [ i + 1 ] ) {
            count += ans [ i ] ;
        } else { // If the current element is greater than or equal to the next element
            // Decrement the current element until it becomes less than the next element
            while ( ans [ i ] >= ans [ i + 1 ] ) {
                ans [ i ] -- ;
            }

            // If the current element is still greater than or equal to the next element, add it to the count
            if ( ans [ i ] > 0 ) {
                count += ans [ i ] ;
            }
        }
    }

    // Printing the final count
    printf ( "%ld\n", count ) ;

    // Freeing the memory allocated for the array
    free ( ans ) ;

    return 0 ;
}

int compare ( const void *a, const void *b ) {
    return ( *( long int * ) a - *( long int * ) b ) ;
}

