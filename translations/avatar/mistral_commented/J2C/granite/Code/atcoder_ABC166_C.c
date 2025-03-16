

#include <stdio.h> // Including the header file for input/output operations

int main ( void ) { // Starting the main method
    int N, M ; // Declaring two integer variables N and M to store the number of elements and queries respectively
    scanf ( "%d %d", &N, &M ) ; // Reading the values of N and M from the user

    int H [ N ] ; // Creating an array of size N to store the heights
    int ans [ N ] ; // Creating an array of size N to store the answer for each index

    for ( int i = 0 ; i < N ; i ++ ) { // Reading the elements of the array H
        scanf ( "%d", &H [ i ] ) ;
        ans [ i ] = 1 ; // Initially assuming that all elements are in the left half
    }

    for ( int query = 0 ; query < M ; query ++ ) { // Processing each query
        int temp1, temp2 ; // Declaring two integer variables temp1 and temp2 to store the indices of the elements
        scanf ( "%d %d", &temp1, &temp2 ) ; // Reading the values of temp1 and temp2 from the user

        if ( H [ temp1 - 1 ] < H [ temp2 - 1 ] ) { // If the height of the first index is less than the second index
            ans [ temp1 - 1 ] = 0 ; // The first index cannot be in the left half
        } else if ( H [ temp1 - 1 ] > H [ temp2 - 1 ] ) { // If the height of the first index is greater than the second index
            ans [ temp2 - 1 ] = 0 ; // The second index cannot be in the left half
        } else { // If the heights are equal
            ans [ temp1 - 1 ] = 0 ; // Both the first and second indices cannot be in the left half
            ans [ temp2 - 1 ] = 0 ;
        }
    }

    int ans2 = 0 ; // Initializing a counter to store the number of elements in the left half
    for ( int i = 0 ; i < N ; i ++ ) { // Iterating through the array to find the number of elements in the left half
        if ( ans [ i ] ) { // If an element is still assumed to be in the left half
            ans2 ++ ; // Increment the counter
        }
    }

    printf ( "%d\n", ans2 ) ; // Printing the final answer

    return 0 ; // Returning 0 to indicate successful execution of the program
}
