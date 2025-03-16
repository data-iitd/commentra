

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for dynamic memory allocation

int main ( void ) {
    int n ; // Declare an integer variable n to store the number of elements in the array
    scanf ( "%d", & n ) ; // Read the number of elements in the array from the standard input stream

    int * a = ( int * ) malloc ( n * sizeof ( int ) ) ; // Dynamically allocate memory for an integer array of size n

    // Read the array elements from the standard input stream and store them in the array
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", & a [ i ] ) ;
    }

    // Sort the array in ascending order using the qsort() function
    qsort ( a, n, sizeof ( int ), cmpfunc ) ;

    int min = a [ 0 ] ; // Assign the minimum value in the array to the min variable

    // Check if all the elements in the array are multiples of the minimum value
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] % min!= 0 ) { // Check if the current element is not a multiple of the minimum value
            printf ( "-1" ) ; // Print -1 if any non-multiple of the minimum value is found
            return 0 ; // Exit the program if any non-multiple of the minimum value is found
        }
    }

    // Print the minimum value if all elements are multiples of the minimum value
    printf ( "%d", min ) ;

    // Free the dynamically allocated memory for the array
    free ( a ) ;

    return 0 ; // Return 0 to indicate successful execution of the program
}

int cmpfunc ( const void * a, const void * b ) {
    // Compare two integers and return a negative value if the first integer is less than the second integer, a positive value if the first integer is greater than the second integer, or zero if the two integers are equal
    if ( *( int * ) a < *( int * ) b ) {
        return - 1 ;
    } else if ( *( int * ) a > *( int * ) b ) {
        return 1 ;
    } else {
        return 0 ;
    }
}

