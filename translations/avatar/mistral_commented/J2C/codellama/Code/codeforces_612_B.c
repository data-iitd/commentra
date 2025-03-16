// Including the header file for the input/output operations
#include <stdio.h>

// Including the header file for the math operations
#include <math.h>

// Defining the main method as the entry point of the program
int main ( ) {
    // Declaring an integer variable n to store the number of test cases
    int n ;

    // Declaring an integer array dp of size 200001 to store the position of each number in the sequence
    int dp [ 200001 ] ;

    // Declaring a long variable ans to store the answer
    long ans ;

    // Reading the number of test cases
    scanf ( "%d", &n ) ;

    // Initializing the answer to 0
    ans = 0 ;

    // Iterating through each test case
    for ( int i = 0 ; i < n ; i ++ ) {
        // Reading the next number to be added to the sequence
        int num ;
        scanf ( "%d", &num ) ;

        // Storing the position of the number in the dp array
        dp [ num ] = i ;
    }

    // Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
    for ( int i = 2 ; i <= n ; i ++ ) {
        // Adding the absolute difference to the answer
        ans += abs ( dp [ i ] - dp [ i - 1 ] ) ;
    }

    // Printing the answer to the console
    printf ( "%ld\n", ans ) ;

    // Ending the program
    return 0 ;
}

