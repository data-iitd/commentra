
#include <stdio.h>

int main ( ) {
    int H, W, A, B; // Initialize variables for grid dimensions and rectangular region
    scanf ( "%d %d %d %d", &H, &W, &A, &B ); // Read input values for H, W, A, and B

    // Check if the grid dimensions meet the conditions
    if ( W < 2 * A || H < 2 * B ) {
        printf ( "-1\n" ); // Print -1 if the conditions are not met
        return 0; // Exit the program
    }

    // Write the grid to the output
    for ( int i = 0 ; i < H ; i ++ ) {
        for ( int j = 0 ; j < W ; j ++ ) {
            // Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ( ( i < B && j < A ) || ( i >= B ) && ( j >= A ) )
                printf ( "0" );
            else
                printf ( "1" );
        }
        printf ( "\n" ); // Move to the next line after writing a row
    }

    return 0; // Return 0 to indicate successful execution
}
