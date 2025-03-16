
#include <stdio.h> // Including the standard header file for input/output operations

int main ( void ) { // Defining the main function that is executed when the program runs
    int n ; // Declaring an integer variable n to store the number of integers
    scanf ( "%d", & n ) ; // Reading the number of integers from the standard input stream and storing it in the variable n

    int result = 0 ; // Initializing the variable result to zero

    int h [ n ] ; // Declaring an integer array h of size n
    int g [ n ] ; // Declaring an integer array g of size n

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each index i from 0 to n-1 in the first for loop
        scanf ( "%d", & h [ i ] ) ; // Reading an integer value from the standard input stream and assigning it to the current index of array h
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each index i from 0 to n-1 in the second for loop
        scanf ( "%d", & g [ i ] ) ; // Reading an integer value from the standard input stream and assigning it to the current index of array g
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each index i from 0 to n-1 in the third for loop
        for ( int j = 0 ; j < n ; j ++ ) { // Nested for loop iterating through each index j from 0 to n-1
            if ( h [ i ] == g [ j ] ) { // Checking if the current element of array h is equal to the current element of array g
                result ++ ; // Incrementing the result variable if the condition is true
            }
        }
    }

    printf ( "%d", result ) ; // Printing the final result to the standard output stream

    return 0 ; // Returning 0 to indicate successful program execution
}

