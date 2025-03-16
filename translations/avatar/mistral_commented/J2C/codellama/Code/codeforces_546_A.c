// Including the header file for the input/output operations
#include <stdio.h>

// Defining the main function
int main ( ) {
    // Declaring and initializing variables for pandu, vundu, urdu and counter c
    long pandu, vundu, urdu, c = 0 ;

    // Reading the values of pandu, vundu and urdu from the console using scanf
    scanf ( "%ld %ld %ld", &pandu, &vundu, &urdu ) ;

    // Using a for loop to calculate the sum of the series and store it in the variable c
    for ( int i = 1 ; i <= urdu ; i ++ ) {
        c += i * pandu ;
        // Comment: Calculating the sum of the series using the formula: c = c + i * pandu
    }

    // Checking if the calculated sum is less than vundu
    if ( c < vundu ) {
        // Comment: If the calculated sum is less than vundu, then print "0"
        printf ( "0" ) ;
    } else {
        // Comment: If the calculated sum is greater than or equal to vundu, then print the difference between the calculated sum and vundu
        printf ( "%ld", c - vundu ) ;
    }

    // Ending the program with comment "