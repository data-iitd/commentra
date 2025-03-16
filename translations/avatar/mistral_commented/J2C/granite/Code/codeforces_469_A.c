

#include <stdio.h> // Include the standard input/output library

int main ( void ) { // Starting point of the program
    int n, levels, sum = 0, sum2 = 0, sum3 = 0, arr [ 100 ], count = 0, level2, level3, arr2 [ 100 ], arr3 [ 100 ], i, j, x; // Declare and initialize variables

    scanf ( "%d %d", &n, &levels ) ; // Read the first two integer inputs 'n' and 'levels'

    for ( i = 0 ; i < levels ; i ++ ) { // Loop to read 'levels' number of integers and store them in 'arr'
        scanf ( "%d", &arr [ i ] ) ;
    }

    scanf ( "%d", &level2 ) ; // Read the third integer input 'level2'
    level3 = levels + level2 ; // Calculate the size of 'arr2'

    for ( i = 0 ; i < levels ; i ++ ) { // Loop to copy elements of 'arr' to 'arr2'
        arr2 [ i ] = arr [ i ] ;
    }

    for ( i = levels ; i < level3 ; i ++ ) { // Loop to read 'level2' number of integers and store them in 'arr2'
        scanf ( "%d", &arr2 [ i ] ) ;
    }

    for ( i = 0 ; i < n ; i ++ ) { // Loop to initialize 'arr3' with numbers from 1 to 'n'
        arr3 [ i ] = ++ j ;
    }

    for ( i = 0 ; i < n ; i ++ ) { // Outer loop to compare each element of 'arr3' with 'arr2'
        for ( x = 0 ; x < level3 ; x ++ ) { // Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
            if ( arr3 [ i ] == arr2 [ x ] ) { // If a match is found
                count ++ ; // Increment the count variable
                break ; // Exit the inner loop
            }
        }
    }

    if ( count == n ) { // If all elements of 'arr3' are present in 'arr2'
        printf ( "I become the guy.\n" ) ; // Print the message
    } else { // Otherwise
        printf ( "Oh, my keyboard!\n" ) ; // Print the error message
    }

    return 0 ; // Return 0 to indicate successful execution
}
