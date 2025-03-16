#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ; // Declaring a variable to store the number of elements
    scanf ( "%d" , &n ) ; // Reading the number of elements
    int array [ 1001 ] = { 0 } ; // Initializing an array to count occurrences
    for ( int i = 0 ; i < n ; i ++ ) { // Looping through each element
        int index ; // Declaring a variable to store the current element
        scanf ( "%d" , &index ) ; // Reading the current element
        array [ index ] ++ ; // Incrementing the count of the current element
    }
    int countMax = - 1 ; // Initializing the maximum count to -1
    for ( int i = 1 ; i < 1001 ; i ++ ) { // Looping through the array to find the maximum count
        if ( countMax < array [ i ] ) countMax = array [ i ] ; // Updating the maximum count if necessary
    }
    if ( n % 2 == 0 ) { // Checking if n is even
        if ( countMax <= n / 2 ) { // Checking if the maximum count is less than or equal to half of n
            printf ( "YES\n" ) ; // Printing "YES" if the condition is met
        } else {
            printf ( "NO\n" ) ; // Printing "NO" if the condition is not met
        }
    } else { // If n is odd
        if ( countMax <= n / 2 + 1 ) { // Checking if the maximum count is less than or equal to half of n rounded up
            printf ( "YES\n" ) ; // Printing "YES" if the condition is met
        } else {
            printf ( "NO\n" ) ; // Printing "NO" if the condition is not met
        }
    }
    return 0 ; // Returning 0
}

