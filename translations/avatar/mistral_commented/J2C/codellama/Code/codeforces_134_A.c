
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n ; // Declaring the number of elements in the array
    int sum = 0 ; // Declaring the sum variable to 0
    int *arr ; // Declaring a pointer to an integer array
    int i ; // Declaring a counter variable
    int c = 0 ; // Declaring the counter variable to 0
    char *sb ; // Declaring a pointer to a character array

    scanf ( "%d", &n ) ; // Reading the number of elements in the array from the standard input
    arr = ( int * ) malloc ( n * sizeof ( int ) ) ; // Allocating memory for the integer array

    for ( i = 0 ; i < n ; i ++ ) { // Starting a for loop to read and store the elements in the array
        scanf ( "%d", &arr [ i ] ) ; // Reading an integer value from the standard input and storing it in the current index of the array
        sum += arr [ i ] ; // Adding the current element to the sum variable
    }

    sb = ( char * ) malloc ( n * sizeof ( char ) ) ; // Allocating memory for the character array

    for ( i = 0 ; i < n ; i ++ ) { // Starting a for loop to check if an element satisfies the condition
        if ( ( sum - arr [ i ] ) % ( n - 1 ) == 0 && ( sum - arr [ i ] ) / ( n - 1 ) == arr [ i ] ) { // Checking if the current element satisfies the condition
            c ++ ; // Incrementing the counter variable if the condition is true
            sb [ i ] = ( i + 1 ) + '0' ; // Appending the index of the current element to the character array
        }
    }

    printf ( "%d\n", c ) ; // Printing the number of elements that satisfy the condition
    printf ( "%s\n", sb ) ; // Printing the indices of the elements that satisfy the condition separated by a space

    free ( arr ) ; // Freeing the memory allocated for the integer array
    free ( sb ) ; // Freeing the memory allocated for the character array

    return 0 ; // Returning 0 to indicate successful execution
}

