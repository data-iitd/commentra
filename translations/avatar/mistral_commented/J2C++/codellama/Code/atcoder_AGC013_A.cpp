
#include <iostream>
#include <cstdlib>

using namespace std ; // Using the standard namespace

int main ( ) { // Starting the main function
    int N ; // Declaring the number of elements in the array
    cin >> N ; // Reading the number of elements in the array from the standard input
    int A [ N ] ; // Creating an integer array of size N

    // Reading the elements of the array from the standard input
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> A [ i ] ;
        // Comment: Reading the i-th element of the array from the standard input
    }

    int count = 0 ; // Initializing the count variable to zero

    // Iterating through the array to find the number of increasing and decreasing sequences
    for ( int i = 0 ; i < N - 1 ; i ++ ) { // Iterating up to the second last index of the array
        if ( i == N - 1 ) count ++ ; // If we have reached the last index, increment the count
        else if ( A [ i ] == A [ i + 1 ] ) ; // If the current and next elements are equal, do nothing
        else if ( A [ i ] < A [ i + 1 ] ) { // If the current element is less than the next element
            while ( A [ i ] <= A [ i + 1 ] ) { // Finding the length of the increasing sequence
                i ++ ;
                if ( i == N - 1 ) break ; // If we have reached the last index, break the loop
            }
            count ++ ; // Increment the count after finding the length of the increasing sequence
        } else { // If the current element is greater than the next element
            while ( A [ i ] >= A [ i + 1 ] ) { // Finding the length of the decreasing sequence
                i ++ ;
                if ( i == N - 1 ) break ; // If we have reached the last index, break the loop
            }
            count ++ ; // Increment the count after finding the length of the decreasing sequence
        }
    }

    cout << count << endl ; // Printing the final count

    return 0 ; // Returning zero to indicate that the program executed successfully
}

