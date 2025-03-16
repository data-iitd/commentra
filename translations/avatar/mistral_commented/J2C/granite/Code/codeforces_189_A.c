

#include <stdio.h> // Including the standard input/output library

int main ( void ) { // Starting the main method
    int n ; // Declaring the variable n to store the number of elements in the array
    scanf ( "%d", & n ) ; // Reading the number of elements in the array from the console

    int maxn = 4010 ; // Defining the maximum size of the dynamic programming array

    int a, b, c ; // Declaring the variables a, b, and c to store the array elements
    scanf ( "%d %d %d", & a, & b, & c ) ; // Reading the three integers representing the array elements from the console

    int arr [ ] = { a, b, c } ; // Defining an array to store the array elements

    int dp [ maxn ] ; // Creating a dynamic programming array of size maxn

    // Initializing the dynamic programming array with minimum values
    for ( int i = 0 ; i < n ; i ++ ) {
        dp [ i ] = - 100000000 ; // Setting all elements to minimum value
    }

    dp [ 0 ] = 0 ; // Setting the first element to 0

    // Filling the dynamic programming array using two nested loops
    for ( int i = 0 ; i < 3 ; i ++ ) { // Looping through the array elements
        for ( int j = arr [ i ] ; j < n ; j ++ ) { // Looping through the dynamic programming array
            dp [ j ] = ( dp [ j ] > dp [ j - arr [ i ] ] + 1 )? dp [ j ] : dp [ j - arr [ i ] ] + 1 ; // Updating the maximum length ending at j
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    printf ( "%d", dp [ n - 1 ] ) ; // Printing the result

    return 0 ; // Returning 0 to indicate successful execution of the program
}

