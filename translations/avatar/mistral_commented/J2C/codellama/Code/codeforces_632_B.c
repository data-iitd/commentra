
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ; // Declaring the number of elements in the array
    scanf ( "%d" , &n ) ; // Reading the number of elements in the array from the standard input
    int a [ n ] ; // Creating an integer array of size n

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the array to read its elements from the standard input
        scanf ( "%d" , &a [ i ] ) ;
    }

    char s [ 100000 ] ; // Creating a character array to store the string
    scanf ( "%s" , s ) ; // Reading the string from the standard input
    long sum = 0 ; // Initializing the sum variable to zero

    for ( int i = 0 ; i < strlen ( s ) ; i ++ ) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'B' characters
        if ( s [ i ] == 'B' ) sum += a [ i ] ;
    }

    long ans = sum ; // Initializing the answer variable with the sum calculated above
    long sum1 = sum ; // Initializing a temporary sum variable with the sum calculated above

    for ( int i = 0 ; i < strlen ( s ) ; i ++ ) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ;
        else sum1 -= a [ i ] ;
        ans = max ( ans , sum1 ) ;
    }

    sum1 = sum ; // Resetting the temporary sum variable with the sum calculated at the beginning

    for ( int i = strlen ( s ) - 1 ; i >= 0 ; i -- ) { // Iterating through the string in reverse order to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ;
        else sum1 -= a [ i ] ;
        ans = max ( ans , sum1 ) ;
    }

    printf ( "%ld\n" , ans ) ; // Printing the maximum sum found
    return 0 ;
}

