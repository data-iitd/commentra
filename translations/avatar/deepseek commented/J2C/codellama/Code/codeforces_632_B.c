#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) { 
    // Step 1: Reading Input
    int n ; // Declare n to store the size of the array
    scanf ( "%d" , &n ) ; // Read the size of the array
    int *a = ( int * ) malloc ( n * sizeof ( int ) ) ; // Initialize the array
    for ( int i = 0 ; i < n ; i ++ ) { 
        scanf ( "%d" , &a [ i ] ) ; // Read the elements of the array
    }
    
    // Step 2: Reading a String
    char s [ 100000 ] ; // Declare s to store the string
    scanf ( "%s" , s ) ; // Read the string
    
    // Step 3: Initial Sum Calculation
    long sum = 0 ; // Declare sum to store the sum of elements in array a where corresponding character in s is 'B'
    
    // Step 4: First Loop
    for ( int i = 0 ; i < strlen ( s ) ; i ++ ) { 
        char ch = s [ i ] ; // Get the character at position i in the string s
        if ( ch == 'B' ) sum += a [ i ] ; // Add the element at position i in array a to sum if the character is 'B'
    }
    
    // Step 5: Main Logic
    long ans = sum ; // Declare ans to store the maximum sum
    long sum1 = sum ; // Declare sum1 to store the sum of elements in array a where corresponding character in s is 'A'
    
    // First nested loop to calculate the maximum possible sum by flipping characters in s
    for ( int i = 0 ; i < strlen ( s ) ; i ++ ) { 
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ; // Add the element at position i in array a to sum1 if the character is 'A'
        else sum1 -= a [ i ] ; // Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = sum1 > ans ? sum1 : ans ; // Update ans with the maximum value between ans and sum1
    }
    
    // Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
    sum1 = sum ; // Reset sum1 to the initial sum
    for ( int i = strlen ( s ) - 1 ; i >= 0 ; i -- ) { 
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ; // Add the element at position i in array a to sum1 if the character is 'A'
        else sum1 -= a [ i ] ; // Subtract the element at position i in array a from sum1 if the character is 'B'
        ans = sum1 > ans ? sum1 : ans ; // Update ans with the maximum value between ans and sum1
    }
    
    // Step 6: Output
    printf ( "%ld\n" , ans ) ; // Print the maximum sum found
    
    return 0 ;
}

