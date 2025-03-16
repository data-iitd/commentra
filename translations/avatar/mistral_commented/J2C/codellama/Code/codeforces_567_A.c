
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int a ; // Declaring variable for storing size of array
    int *ar ; // Declaring pointer for array
    int max , min ; // Declaring variables for storing maximum and minimum differences

    // Asking user for the size of the array and initializing it
    printf ( "Enter the size of the array: " ) ;
    scanf ( "%d" , &a ) ;
    ar = ( int * ) malloc ( a * sizeof ( int ) ) ;

    // Reading array elements from user input
    for ( int i = 0 ; i < a ; i ++ ) {
        printf ( "Enter element %d: " , i + 1 ) ;
        scanf ( "%d" , &ar [ i ] ) ;
    }

    // Finding maximum and minimum differences between consecutive elements in the array
    for ( int i = 0 ; i < a ; i ++ ) {
        // Finding maximum difference between current element and first element
        max = ar [ i ] - ar [ 0 ] ;

        // Finding minimum difference between current element and previous element
        if ( i == 0 ) {
            min = ar [ i + 1 ] - ar [ i ] ;
        } else if ( i == a - 1 ) {
            min = ar [ i ] - ar [ i - 1 ] ;
        } else {
            min = ar [ i ] - ar [ i - 1 ] ;
            if ( min > ar [ i + 1 ] - ar [ i ] ) {
                min = ar [ i + 1 ] - ar [ i ] ;
            }
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        printf ( "%d %d\n" , min , max ) ;
    }

    // Freeing memory allocated for array
    free ( ar ) ;

    return 0 ;
}

