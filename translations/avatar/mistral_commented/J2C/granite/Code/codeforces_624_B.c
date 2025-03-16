

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for memory allocation and sorting

int main ( void ) { // Main function to start the program
    int n ; // Declare a variable to store the number of elements in the array
    scanf ( "%d", & n ) ; // Read the number of elements in the array from the user

    // Allocate memory for the array and initialize it with user input
    long * ans = ( long * ) malloc ( n * sizeof ( long ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%ld", & ans [ i ] ) ; // Read each element of the array one by one
    }

    // Sort the array in ascending order
    qsort ( ans, n, sizeof ( long ), cmpfunc ) ;

    // Initialize a variable to keep track of the count
    long count = ans [ n - 1 ] ; // The last element of the sorted array is the maximum element

    // Iterate through the array from the second last element to the first
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

    // Print the final count
    printf ( "%ld", count ) ;

    // Free the allocated memory for the array
    free ( ans ) ;

    return 0 ; // Return 0 to indicate successful execution of the program
}

// Define a comparison function for sorting the array
int cmpfunc ( const void * a, const void * b ) {
    return ( * ( long * ) a - * ( long * ) b ) ; // Compare two elements of the array
}

Translate the above C code to Python and end with comment "