

#include <stdio.h>  // Include necessary header files for input and output
#include <stdlib.h>
#include <string.h>

int main ( ) {
    // Creating a file pointer for reading input from the standard input
    FILE * in = stdin ;
    // Creating a file pointer for writing output to the standard output
    FILE * out = stdout ;

    // Reading the number of elements in the list from the input
    int n ;
    fscanf ( in, "%d", & n ) ;

    // Creating an array of size 'n' to store the elements
    int * list = ( int * ) malloc ( n * sizeof ( int ) ) ;

    // Reading 'n' elements from the input and storing them in the array
    for ( int i = 0 ; i < n ; i ++ ) {
        fscanf ( in, "%d", & list [ i ] ) ;  // Reading an integer from the input and storing it in the array
    }

    // Sorting the array in ascending order using qsort() function
    qsort ( list, n, sizeof ( int ), cmpfunc ) ;

    // Initializing a variable 'c' to keep track of the number of distinct elements
    int c = 1 ;

    // Iterating through the array to find the number of distinct elements
    for ( int i = 0 ; i < n ; i ++ ) {
        // If the current element is greater than or equal to the current count 'c', increment the count
        if ( list [ i ] >= c ) {
            c ++ ;
        }
    }

    // Writing the result to the output
    fprintf ( out, "%d\n", c ) ;

    // Freeing the memory allocated for the array
    free ( list ) ;

    // Debugging method to print the deep toString representation of an object
    static void debug ( Object...obj ) {
        System.err.println ( Arrays.deepToString ( obj ) ) ;
    }
}

