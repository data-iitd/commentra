#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM (int)(1e5 + 2)

int main ( ) {
    int N ; // Declaring the number of elements in the array
    scanf ( "%d" , & N ) ; // Reading the number of elements in the array

    // Creating an empty HashMap to store the index of each unique element
    int map [ NUM ] ;
    for ( int i = 0 ; i < NUM ; i ++ ) {
        map [ i ] = -1 ;
    }

    // Creating an empty PriorityQueue to store the elements in ascending order
    int nums [ NUM ] ;
    int nums_size = 0 ;

    // Reading the elements one by one and adding them to the PriorityQueue and HashMap
    for ( int i = 0 ; i < N ; i ++ ) {
        int tmp ; // Declaring a temporary variable to store the element
        scanf ( "%d" , & tmp ) ; // Reading an element

        // Checking if the element is already present in the HashMap
        if ( map [ tmp ] == -1 ) {
            map [ tmp ] = i ; // Adding the index of the element to the HashMap
            nums [ nums_size ] = tmp ; // Adding the element to the PriorityQueue
            nums_size ++ ;
        }
    }

    int bin = 0 ; // Initializing a binary index variable
    int diff = 0 ; // Initializing a variable to store the difference in parity between elements

    // Processing the elements in the PriorityQueue
    while ( nums_size > 0 ) {
        int num = nums [ 0 ] ; // Polling an element from the PriorityQueue
        int idx = map [ num ] ; // Getting the index of the element from the HashMap

        // Checking if the binary index and the index of the current element have opposite parity
        if ( ( bin % 2 ) != ( idx % 2 ) ) {
            diff ++ ; // Incrementing the difference if the condition is true
        }

        bin ++ ; // Incrementing the binary index
        bin %= 2 ; // Setting the binary index to 0 or 1 based on the current parity

        // Removing the element from the PriorityQueue
        for ( int i = 0 ; i < nums_size - 1 ; i ++ ) {
            nums [ i ] = nums [ i + 1 ] ;
        }
        nums_size -- ;
    }

    // Calculating and printing the answer
    int ans = ( diff / 2 ) ;
    printf ( "%d\n" , ans ) ;

    return 0 ;
}

