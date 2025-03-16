#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int N ; // Declare a variable to store the number of elements N
    scanf ( "%d", &N ) ; // Read the number of elements N from the standard input
    int *A = ( int * ) malloc ( N * sizeof ( int ) ) ; // Create an integer array A of size N to store the elements

    // Use a for loop to read each element from the standard input and store it in the corresponding index of the array A
    for ( int n = 0 ; n < N ; n ++ ) {
        scanf ( "%d", &A [ n ] ) ;
    }

    // Use the qsort() function to sort the elements in the array A in ascending order
    qsort ( A, N, sizeof ( int ), compare ) ;

    // Initialize two variables, min and max, to store the minimum and maximum elements in the array A, respectively
    int min = A [ 0 ] ;
    int max = A [ N - 1 ] ;

    // Use a for loop to iterate through each element in the array A and perform some checks
    for ( int n = 0 ; n < N ; n ++ ) {
        if ( A [ n ] == min ) { // If the current element is equal to the minimum element min, increment the variable mins by 1
            mins ++ ;
        }
        if ( A [ n ] == max ) { // If the current element is equal to the maximum element max, increment the variable maxs by 1
            maxs ++ ;
        }
    }

    // Check if the minimum and maximum elements are the same
    if ( min == max ) {
        long result = ( max - min ) + 1 ; // Calculate the difference between the minimum and maximum elements, plus 1
        result *= mins ; // Multiply the result by the number of occurrences of the minimum element
        result -= mins * ( mins - 1 ) / 2 ; // Subtract the number of combinations of pairs of minimum elements
        printf ( "%ld\n", result ) ; // Print the output
    } else {
        long result = ( max - min ) ; // Calculate the difference between the minimum and maximum elements
        result *= mins ; // Multiply the result by the number of occurrences of the minimum element
        result *= maxs ; // Multiply the result by the number of occurrences of the maximum element
        printf ( "%ld\n", result ) ; // Print the output
    }

    free ( A ) ; // Free the memory allocated for the array A
    return 0 ;
}

// Define a static compare function to compare two integers for sorting purposes
int compare ( const void *a, const void *b ) {
    return ( *( int * ) a - *( int * ) b ) ;
}

// Define a static debug function to print the contents of an array or other objects for debugging purposes
void debug ( void *obj ) {
    printf ( "%s\n", ( char * ) obj ) ;
}

