

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library
#include <string.h> // Include the string library
#include <math.h> // Include the mathematical library
#include <time.h> // Include the time library
#include <assert.h> // Include the assert library

int main ( int argc, char * argv [ ] ) { // Define the main function as the entry point of the program
    int N ; // Define an integer variable N to store the number of elements in the array
    scanf ( "%d", & N ) ; // Read the number of elements N from the standard input and store it in the variable N

    int * A = ( int * ) malloc ( N * sizeof ( int ) ) ; // Allocate memory for an array of N integers

    for ( int i = 0 ; i < N ; i ++ ) { // Use a for loop to read N integers from the standard input and store them in the array A
        scanf ( "%d", & A [ i ] ) ;
    }

    qsort ( A, N, sizeof ( int ), cmpfunc ) ; // Sort the array A using the qsort() function

    int count = 0 ; // Initialize a counter variable to 0

    for ( int i = 0 ; i < N ; i ++ ) { // Use a for loop to iterate through all pairs of adjacent elements in the sorted array A
        for ( int j = i + 1 ; j < N ; j ++ ) {
            int a = A [ i ] ; // Get the first integer of the pair
            int b = A [ j ] ; // Get the second integer of the pair
            int res = find ( A, j + 1, a + b ) ; // Call the find() function to find the number of elements greater than the sum of the pair
            count = count + res ; // Add the result of the find() function to the counter variable
        }
    }

    printf ( "%d", count ) ; // Print the final value of the counter variable to the standard output stream

    free ( A ) ; // Free the memory allocated for the array A

    return 0 ; // Return 0 to indicate successful execution of the program
}

int cmpfunc ( const void * a, const void * b ) { // Define a comparison function for qsort() that compares two integers
    if ( *( int * ) a < *( int * ) b ) { // If the first integer is less than the second integer, return -1
        return -1 ;
    } else if ( *( int * ) a > *( int * ) b ) { // If the first integer is greater than the second integer, return 1
        return 1 ;
    } else { // If the first integer is equal to the second integer, return 0
        return 0 ;
    }
}

int find ( int * A, int from, int target ) { // Define the find() function that takes three arguments: a pointer to an array of integers, an index from where to start the search, and a target integer
    int low = from ; // Initialize the lower bound of the binary search
    int upp = N - 1 ; // Initialize the upper bound of the binary search
    int mid = 0 ; // Initialize a variable to store the middle index of the binary search

    if ( upp - low < 0 ) { // Check if the array is empty or the target integer is less than the first element
        return 0 ;
    } else if ( A [ from ] >= target ) { // Check if the target integer is greater than or equal to the first element
        return 0 ;
    } else if ( A [ upp ] < target ) { // Check if the target integer is less than the last element
        return upp - low + 1 ;
    }

    while ( upp - low > 1 ) { // Perform the binary search
        mid = ( upp - low + 1 ) % 2 == 0? ( low + upp ) / 2 + 1 : ( low + upp ) / 2 ; // Calculate the middle index of the binary search

        if ( A [ mid ] >= target ) { // If the middle element is greater than or equal to the target, update the upper bound of the search
            upp = mid ;
        } else { // If the middle element is less than the target, update the lower bound of the search
            low = mid ;
        }
    }

    return low - from + 1 ; // Return the index of the middle element minus the starting index plus one
}

