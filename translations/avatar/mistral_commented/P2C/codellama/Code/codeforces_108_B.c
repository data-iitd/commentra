
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function named s that takes no arguments
void s ( ) {

    // Read input as a list of integers
    int *input_list = ( int * ) malloc( sizeof( int ) * 100 );
    int i = 0;
    while ( scanf( "%d", &input_list[i] ) != EOF ) {
        i++;
    }

    // Sort the input list in ascending order
    qsort( input_list, i, sizeof( int ), compare );

    // Initialize a variable to store the result
    char result[100] = "NO";

    // Iterate through the sorted list starting from the second element
    for ( int j = 1; j < i; j++ ) {

        // Compare the current element with the previous one
        int current_element = input_list[j];
        int previous_element = input_list[j-1];

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if ( current_element < previous_element * 2 && current_element != previous_element ) {

            // If the condition is true, set the result to 'YES'
            strcpy( result, "YES" );

            // Break out of the loop since we have found the answer
            break;
        }
    }

    // Print the result
    printf( "%s\n", result );

    // Free the memory allocated for the input list
    free( input_list );
}

// Define a function named compare that takes two integers as arguments
// and returns an integer
int compare ( const void *a, const void *b ) {

    // Cast the arguments to integers
    int int_a = *( int * ) a;
    int int_b = *( int * ) b;

    // Return the difference between the two integers
    return int_a - int_b;
}

int main ( ) {

    // Call the function s
    s( );

    return 0;
}

