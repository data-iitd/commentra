
#include <stdio.h>

int main( ) {

    // Get the input as a list of two integers, S and W, using the scanf function
    int S, W;
    scanf( "%d %d", &S, &W );

    // Check if the condition S <= W is true or false and print the corresponding message
    if ( S <= W ) {
        printf( "unsafe\n" );
    } else {
        printf( "safe\n" );
    }

    // Return 0 to indicate successful execution
    return 0;
}

