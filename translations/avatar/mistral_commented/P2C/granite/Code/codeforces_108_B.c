

#include <stdio.h>
#include <stdlib.h>

int main ( ) {

    // Read input as a list of integers
    int n;
    scanf( "%d", &n );
    int *input_list = ( int * ) malloc( n * sizeof( int ) );
    for ( int i = 0; i < n; i++ ) {
        scanf( "%d", &input_list[i] );
    }

    // Sort the input list in ascending order
    qsort( input_list, n, sizeof( int ), compare );

    // Initialize a variable to store the result
    char result[5] = "NO";

    // Iterate through the sorted list starting from the second element
    for ( int i = 1; i < n; i++ ) {

        // Compare the current element with the previous one
        int current_element = input_list[i];
        int previous_element = input_list[i-1];

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if ( current_element < previous_element * 2 && current_element!= previous_element ) {

            // If the condition is true, set the result to 'YES'
            result[0] = 'Y';
            result[1] = 'E';
            result[2] = 'S';

            // Break out of the loop since we have found the answer
            break;
        }
    }

    // Print the result
    printf( "%s\n", result );

    // Free the memory allocated for the input list
    free( input_list );

    return 0;
}

int compare ( const void * a, const void * b ) {
    return ( *( int * ) a - *( int * ) b );
}

