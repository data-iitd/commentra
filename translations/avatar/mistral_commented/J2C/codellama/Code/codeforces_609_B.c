#include <stdio.h>

// Main method is the entry point of the C application
int main ( ) {

    // Creating a new Scanner object to read input from the standard input stream
    int n, m, i, k ;
    scanf ( "%d %d", &n, &m ) ;

    // Creating an integer array arr of size n to store the input integers
    int arr [ n ] ;

    // Creating an integer array gen of size 11 to store the count of each integer occurrence
    int gen [ 11 ] ;

    // Reading the input integers and storing them in the arr array
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &arr [ i ] ) ;
        // Incrementing the count of the arr[i] in the gen array
        gen [ arr [ i ] ] ++ ;
    }

    // Calculating the answer
    long ans = 0 ;
    for ( i = 1 ; i <= m ; i ++ ) {
        for ( k = 1 ; k <= m ; k ++ ) {
            // Skipping the case when i and k are equal to avoid double counting
            if ( i != k ) {
                // Multiplying the count of i and k and adding it to the answer
                ans += ( long ) gen [ i ] * gen [ k ] ;
            }
        }
    }

    // Printing the answer divided by 2
    printf ( "%ld\n", ans / 2 ) ;

    // End of code
    return 0 ;
}