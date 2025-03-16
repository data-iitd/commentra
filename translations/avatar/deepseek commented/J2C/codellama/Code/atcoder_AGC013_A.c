
#include <stdio.h> 
#include <stdlib.h> 

int main ( ) { 
    int N ; // Step 1: Declare a variable 'N' to store the input value
    scanf ( "%d", &N ) ; // Step 2: Read the input value 'N'
    int * A = ( int * ) malloc ( N * sizeof ( int ) ) ; // Step 3: Allocate memory for the array 'A'
    for ( int i = 0 ; i < N ; i ++ ) { 
        scanf ( "%d", &A [ i ] ) ; // Step 4: Read the elements of the array 'A'
    } 
    int count = 0 ; // Step 5: Initialize a counter 'count' to zero
    for ( int i = 0 ; i < N ; i ++ ) { 
        if ( i == N - 1 ) 
            count ++ ; // Step 7: Check if the current index 'i' is the last index
        else if ( A [ i ] == A [ i + 1 ] ) ; // Step 8: If the current element is equal to the next element
        else if ( A [ i ] < A [ i + 1 ] ) { 
            while ( A [ i ] <= A [ i + 1 ] ) { 
                i ++ ; 
                if ( i == N - 1 ) break ; 
            } 
            count ++ ; // Step 9: Increment the counter 'count' after each segment
        } else { 
            while ( A [ i ] >= A [ i + 1 ] ) { 
                i ++ ; 
                if ( i == N - 1 ) break ; 
            } 
            count ++ ; // Step 10: Increment the counter 'count' after each segment
        } 
    } 
    printf ( "%d\n", count ) ; // Step 11: Print the value of the counter 'count'
    free ( A ) ; // Step 12: Free the memory allocated for the array 'A'
    return 0 ; 
}

