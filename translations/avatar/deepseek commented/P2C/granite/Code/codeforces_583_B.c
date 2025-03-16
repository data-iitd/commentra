

#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Read the number of elements from the user
    int n;
    scanf ( "%d", & n );
    // Read the list of integers from the user input
    int * a = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0; i < n; i ++ ) {
        scanf ( "%d", & a [ i ] );
    }
    
    // Initialize variables to track the current level and the number of turns
    int current_level = 0;
    int counter = 0;
    int counter_turns = - 1;
    
    // Start a while loop that continues until all elements are processed
    while ( counter < n ) {
        // Increment the turn counter
        counter_turns += 1;
        // Iterate over the list 'a' to process each element
        for ( int i = 0; i < n; i ++ ) {
            // Check if the element is not -1 and is less than or equal to the current level
            if ( a [ i ]!= - 1 && a [ i ] <= counter ) {
                // Increment the counter and mark the element as processed
                counter += 1;
                a [ i ] = - 1;
            }
        }
        // Reverse the list 'a' to process elements in a different order in the next iteration
        for ( int i = 0; i < n / 2; i ++ ) {
            int temp = a [ i ];
            a [ i ] = a [ n - i - 1 ];
            a [ n - i - 1 ] = temp;
        }
    }
    
    // Print the number of turns taken to process all elements
    printf ( "%d", counter_turns );
    
    // Free the memory allocated for the list 'a'
    free ( a );
    
    return 0;
}
