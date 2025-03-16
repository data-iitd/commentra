
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int n ; // Defining the number of elements in the array
    int maxn = 4010 ; // Defining the maximum size of the dynamic programming array
    int a , b , c ; // Defining the three integers representing the array elements
    int *arr ; // Defining an array to store the array elements
    int *dp ; // Defining a dynamic programming array of size maxn
    int i , j ; // Defining two integers to loop through the array and dynamic programming array

    // Reading the number of elements in the array from the console
    scanf ( "%d" , &n ) ;

    // Reading the three integers representing the array elements
    scanf ( "%d %d %d" , &a , &b , &c ) ;

    // Defining an array to store the array elements
    arr = ( int * ) malloc ( 3 * sizeof ( int ) ) ;
    arr [ 0 ] = a ;
    arr [ 1 ] = b ;
    arr [ 2 ] = c ;

    // Defining a dynamic programming array of size maxn
    dp = ( int * ) malloc ( maxn * sizeof ( int ) ) ;

    // Initializing the dynamic programming array with minimum values
    for ( i = 0 ; i < n ; i ++ ) {
        dp [ i ] = INT_MIN ; // Setting all elements to minimum value
    }

    dp [ 0 ] = 0 ; // Setting the first element to 0

    // Filling the dynamic programming array using two nested loops
    for ( i = 0 ; i < 3 ; i ++ ) { // Looping through the array elements
        for ( j = arr [ i ] ; j < maxn ; j ++ ) { // Looping through the dynamic programming array
            dp [ j ] = max ( dp [ j ] , dp [ j - arr [ i ] ] + 1 ) ; // Updating the maximum length ending at j
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    printf ( "%d\n" , dp [ n ] ) ;

    // Freeing the memory allocated to the arrays
    free ( arr ) ;
    free ( dp ) ;

    return 0 ;
}

