
#include <stdio.h>
#include <stdlib.h>

int main ( void ) {
    int N ; // Define an integer variable N to store the number of elements
    scanf ( "%d", & N ) ; // Read the number of elements N from the standard input using scanf()

    int * A = ( int * ) malloc ( N * sizeof ( int ) ) ; // Allocate memory for an integer array A of size N using malloc()

    // Use a for loop to read each element from the standard input and store it in the corresponding index of the array A
    for ( int n = 0 ; n < N ; n ++ ) {
        scanf ( "%d", & A [ n ] ) ;
    }

    // Use the qsort() function to sort the elements in the array A in ascending order
    qsort ( A, N, sizeof ( int ), cmpfunc ) ;

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
        printf ( "%ld\n", result ) ; // Print the output using printf()
    } else {
        long result = ( max - min ) ; // Calculate the difference between the minimum and maximum elements
        result *= mins ; // Multiply the result by the number of occurrences of the minimum element
        result *= maxs ; // Multiply the result by the number of occurrences of the maximum element
        printf ( "%ld\n", result ) ; // Print the output using printf()
    }

    free ( A ) ; // Free the memory allocated for the array A using free()

    return 0 ; // Return 0 to indicate successful execution of the program
}

// Define a static cmpfunc function to compare two integers for sorting purposes
static int cmpfunc ( const void * a, const void * b ) {
    return ( * ( int * ) a - * ( int * ) b ) ; // Compare two integers and return their difference
}

Translate the above C code to Python and end with comment "