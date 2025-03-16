
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n ; // Declaring a variable to store the number of elements in the array
    int *a ; // Declaring a pointer to an integer array to store the array
    int min ; // Declaring a variable to store the minimum value in the array

    // Reading the number of elements in the array from the user input
    scanf ( "%d", &n ) ;

    // Dynamically allocating memory for the array
    a = ( int * ) malloc ( n * sizeof ( int ) ) ;

    // Initializing the array with user input
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &a [ i ] ) ; // Reading an integer value from the user input and storing it in the array at the current index
    }

    // Sorting the array in ascending order using the qsort() function
    qsort ( a, n, sizeof ( int ), compare ) ;

    min = a [ 0 ] ; // Assigning the minimum value in the array to the min variable

    // Checking if all the elements in the array are multiples of the minimum value
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] % min != 0 ) { // Checking if the current element is not a multiple of the minimum value
            printf ( "-1\n" ) ; // Printing -1 if any non-multiple of the minimum value is found
            return 0 ; // Exiting the function if any non-multiple of the minimum value is found
        }
    }

    // Printing the minimum value if all elements are multiples of the minimum value
    printf ( "%d\n", min ) ;

    return 0 ;
}

int compare ( const void *a, const void *b ) {
    return ( *( int * ) a - *( int * ) b ) ;
}

