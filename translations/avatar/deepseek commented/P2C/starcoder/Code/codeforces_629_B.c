
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Define the maximum number of time slots
    int N = 368;

    // Initialize lists to store changes for males and females
    int * m = ( int * ) malloc ( N * sizeof ( int ) ) ;
    int * f = ( int * ) malloc ( N * sizeof ( int ) ) ;

    // Read the number of operations
    int n;
    scanf ( "%d", & n ) ;

    // Read each line, strip newline, and split into gender, start time, and end time
    for ( int i = 0 ; i < n ; i ++ ) {
        char x [ 10 ] ;
        int a, b ;
        scanf ( "%s %d %d", x, & a, & b ) ;
        a -- ;
        b -- ;

        // Update the changes in the lists based on gender
        if ( x [ 0 ] == 'M' ) {
            m [ a ] += 2 ;
            m [ b ] -= 2 ;
        }
        else {
            f [ a ] += 2 ;
            f [ b ] -= 2 ;
        }
    }

    // Initialize variables to store the maximum number of people and the current number of people
    int a = 0, b = 0, c = 0 ;

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for ( int i = 0 ; i < N ; i ++ ) {
        a += m [ i ] ;
        b += f [ i ] ;
        if ( min ( a, b ) > c ) {
            c = min ( a, b ) ;
        }
    }

    // Print the maximum number of people at any time slot
    printf ( "%d\n", c ) ;

    // Free the memory
    free ( m ) ;
    free ( f ) ;

    return 0 ;
}

