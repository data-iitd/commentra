
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    int num = 998244353 ;  // Initializing a variable 'num' with a value
    int n ;  // Declaring a variable 'n' to store the number of test cases
    scanf ( "%d", &n ) ;  // Reading the number of test cases from the standard input stream
    int *ai = ( int * ) malloc ( n * sizeof ( int ) ) ;  // Creating an array to store the first array elements
    int *bi = ( int * ) malloc ( n * sizeof ( int ) ) ;  // Creating an array to store the second array elements

    for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through the test cases
        scanf ( "%d %d", &ai [ i ], &bi [ i ] ) ;  // Reading the first and second array elements from the standard input stream
    }

    // Sorting the arrays in ascending order
    qsort ( ai, n, sizeof ( int ), compare ) ;
    qsort ( bi, n, sizeof ( int ), compare ) ;

    if ( n % 2 == 1 ) {  // Checking if the number of test cases is odd
        printf ( "%d\n", bi [ n / 2 ] - ai [ n / 2 ] + 1 ) ;  // Calculating and printing the answer for odd number of test cases
    } else {
        double b = ( ai [ n / 2 ] + ai [ n / 2 - 1 ] + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the first array
        double c = ( bi [ n / 2 ] + bi [ n / 2 - 1 ] + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the second array
        printf ( "%d\n", ( int ) ( 2 * ( c - b ) + 1 ) ) ;  // Calculating and printing the answer for even number of test cases
    }

    free ( ai ) ;  // Freeing the memory allocated for the first array
    free ( bi ) ;  // Freeing the memory allocated for the second array

    return 0 ;  // Returning 0 to indicate successful execution
}

int compare ( const void *a, const void *b ) {
    return ( *( int * ) a - *( int * ) b ) ;  // Comparing the two elements and returning the difference
}

