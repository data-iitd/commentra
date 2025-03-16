
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Initialize scanner for user input
int main ( ) {
    // Read the number of slimes N from user input
    int N ;
    scanf ( "%d", &N ) ;
    // Calculate the size of the array S based on N
    int size = ( 1 << N ) ;
    // Initialize the array S with user input
    int * S = ( int * ) malloc ( size * sizeof ( int ) ) ;
    // Initialize a boolean array spawned to keep track of which slimes have been spawned
    bool * spawned = ( bool * ) malloc ( size * sizeof ( bool ) ) ;
    // Set the last element of spawned to true, as it represents the position of the last slime
    spawned [ size - 1 ] = true ;

    // Read the initial positions of slimes from user input and store them in array S
    for ( int i = 0 ; i < size ; i ++ ) {
        scanf ( "%d", &S [ i ] ) ;
    }
    // Sort the array S in ascending order
    qsort ( S, size, sizeof ( int ), compare ) ;

    // Initialize an ArrayList named active to store the indices of the currently active slimes
    int * active = ( int * ) malloc ( size * sizeof ( int ) ) ;
    // Set the last element of spawned to true and add its index to the active list
    active [ size - 1 ] = size - 1 ;
    spawned [ size - 1 ] = true ;

    // Iterate through each generation of slimes
    for ( int i = 0 ; i < N ; i ++ ) {
        // Sort the ArrayList active in descending order
        qsort ( active, size, sizeof ( int ), compare ) ;

        // Initialize an ArrayList named activated to store the indices of the slimes that will be activated in the next generation
        int * activated = ( int * ) malloc ( size * sizeof ( int ) ) ;
        // Initialize a variable named next to keep track of the index of the current slime in array S
        int next = size - 1 ;

        // Iterate through each slime in the current generation
        for ( int j = 0 ; j < size ; j ++ ) {
            // While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
            while ( next >= 0 && ( S [ next ] >= active [ j ] || spawned [ next ] ) ) {
                next -- ;
            }
            // If the current index next is less than 0, it means that there is no empty space for the new slime to spawn, so print "No" and exit the program
            if ( next < 0 ) {
                printf ( "No\n" ) ;
                return 0 ;
            }
            // Set the current index as spawned and add its index to the activated ArrayList
            spawned [ next ] = true ;
            activated [ j ] = S [ next ] ;
        }
        // Add all the indices of the activated slimes to the active ArrayList
        for ( int j = 0 ; j < size ; j ++ ) {
            active [ j ] = activated [ j ] ;
        }
    }

    // Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
    printf ( "Yes\n" ) ;
    return 0 ;
}

int compare ( const void * a, const void * b ) {
    return ( * ( int * ) a - * ( int * ) b ) ;
}

