
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int N ; // Declare a variable to store the number of integers
    scanf ( "%d" , &N ) ; // Read the number of integers from the standard input

    int *L = ( int * ) malloc ( N * sizeof ( int ) ) ; // Allocate memory for an array of integers

    for ( int i = 0 ; i < N ; i ++ ) { // Read N integers from the standard input and store them in the array
        scanf ( "%d" , &L [ i ] ) ;
    }

    qsort ( L , N , sizeof ( int ) , compare ) ; // Sort the array using the qsort() function

    int count = 0 ; // Initialize a variable to store the number of pairs

    for ( int i = 0 ; i < N ; i ++ ) { // Iterate through all pairs of adjacent elements in the sorted array
        for ( int j = i + 1 ; j < N ; j ++ ) {
            int a = L [ i ] ; // Get the first integer of the pair
            int b = L [ j ] ; // Get the second integer of the pair
            int res = find ( L , j + 1 , a + b ) ; // Call the find() function to find the number of elements greater than the sum of the pair
            count = count + res ; // Add the result of the find() function to the counter variable
        }
    }

    printf ( "%d\n" , count ) ; // Print the final value of the counter variable to the standard output

    free ( L ) ; // Free the memory allocated for the array

    return 0 ;
}

int compare ( const void *a , const void *b ) { // Define the compare() function that compares two integers
    return ( *( int * ) a - *( int * ) b ) ;
}

int find ( int *L , int from , int target ) { // Define the find() function that takes three arguments: an array of integers, an index from where to start the search, and a target integer
    int low = from ; // Initialize the lower bound of the binary search
    int upp = sizeof ( L ) / sizeof ( int ) - 1 ; // Initialize the upper bound of the binary search
    int mid = 0 ; // Initialize a variable to store the middle index of the binary search

    if ( upp - low < 0 ) { // Check if the array is empty or the target integer is less than the first element
        return 0 ;
    } else if ( L [ from ] >= target ) { // Check if the target integer is greater than or equal to the first element
        return 0 ;
    } else if ( L [ upp ] < target ) { // Check if the target integer is less than the last element
        return upp - low + 1 ;
    }

    while ( upp - low > 1 ) { // Perform the binary search
        mid = ( upp - low + 1 ) % 2 == 0 ? ( low + upp ) / 2 + 1 : ( low + upp ) / 2 ; // Calculate the middle index of the binary search

        if ( L [ mid ] >= target ) { // If the middle element is greater than or equal to the target, update the upper bound of the search
            upp = mid ;
        } else { // If the middle element is less than the target, update the lower bound of the search
            low = mid ;
        }
    }

    return low - from + 1 ; // Return the index of the middle element minus the starting index plus one
}

