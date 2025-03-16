#include <stdio.h>
#include <stdlib.h>

// Define the main function that takes no arguments and returns nothing
int main( ) {

    // Declare variables S and W as integers
    int S, W;

    // Get the input as a list of two integers, S and W, using the scanf function
    scanf( "%d %d", &S, &W );

    // Check if the condition S <= W is true or false and print the corresponding message
    if ( S <= W ) {
        printf( "unsafe\n" );
    } else {
        printf( "safe\n" );
    }

    // Return 0 to indicate that the program ended successfully
    return 0;
}

// End of code
