
###
# Code
###

# Include the necessary header file
#include <stdio.h>

// Define a macro to read a line of input and convert it to a list of integers
#define R() { int a[4]; int i = 0; char c; while ( ( c = getchar ( ) )!= '\n' ) { a[i++] = ( c >= '0' && c <= '9' )? ( c - '0' ) : ( c - 'A' + 10 ); } return a; }

// Define a macro to print the output string
#define P(s) { printf ( "%s\n", s ); }

// Define a macro to convert an integer to a character
#define I2C(i) ( ( i >= 0 && i <= 9 )? ( '0' + i ) : ( 'A' + i - 10 ) )

// Define a macro to convert a character to an integer
#define C2I(c) ( ( c >= '0' && c <= '9' )? ( c - '0' ) : ( c - 'A' + 10 ) )

// Define a macro to check if the current position i is in the current track
#define IN_TRACK(i,t,l,r) ( ( i == t && ( l <= j && j <= r ) ) || ( i < t && ( l <= j && j <= r ) ) || ( i > t && ( l <= j + d && j + d <= r ) ) )

// Define a macro to append a character to the output string
#define APPEND(c) { res[k++] = c; }

// Define a macro to append 'X' to the output string
#define APPEND_X() { res[k++] = 'X'; }

// Define a macro to update the current position j based on the direction
#define UPDATE_J() { j += d; }

// Define a macro to increment the current position i
#define INCREMENT_I() { i++; }

// Define a macro to check if the starting position is less than the final position
#define START_LESS_THAN_FINISH() ( s < f )

// Define a macro to initialize direction and corresponding character
#define INIT_DIRECTION_AND_CHAR() { if ( s < f ) { d = 1; c = 'R'; } else { d = - 1; c = 'L'; } }

// Define a macro to initialize an empty string to store the output
#define INIT_RES() { char res[100000]; int k = 0; }

// Define a macro to initialize variables i and j with initial values
#define INIT_I_AND_J() { int i = 1; int j = s; }

// Define a macro to read the next input: three integers t, l, and r representing the length, left end, and right end of a track
#define READ_NEXT_TRACK() { int a[3] = R(); int t = a[0]; int l = a[1]; int r = a[2]; }

// Define a macro to increment the number of tracks
#define INCREMENT_K() { k++; }

// Define a macro to print the output string
#define PRINT_RES() { P(res); }

// Main function
int main ( ) {
    // Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
    int n = R()[0];
    int m = R()[1];
    int s = R()[2];
    int f = R()[3];

    // Check if the starting position is less than the final position
    if ( START_LESS_THAN_FINISH ( ) ) {
        // Initialize direction and corresponding character
        INIT_DIRECTION_AND_CHAR ( );
    } else {
        // Initialize direction with negative sign and corresponding character 'L'
        d = - 1;
        c = 'L';
    }

    // Initialize an empty string to store the output
    INIT_RES ( );

    // Initialize variables i and j with initial values
    INIT_I_AND_J ( );

    // Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
    READ_NEXT_TRACK ( );

    // Initialize a variable k to keep track of the number of tracks
    int k = 1;

    // While the current position j is not equal to the final position f
    while ( j!= f ) {
        // If we have read all the tracks or the current position i is not in the current track
        if ( i > t && k < m ) {
            // Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
            READ_NEXT_TRACK ( );
            // Increment the number of tracks
            INCREMENT_K ( );
        }

        // If the current position i is in the current track (either it is the same track or it overlaps with the current track)
        if ( IN_TRACK ( i, t, l, r ) ) {
            // Append 'X' to the output string
            APPEND_X ( );
        } else {
            // Append the corresponding direction character 'R' or 'L' to the output string
            APPEND ( c );
            // Update the current position j based on the direction
            UPDATE_J ( );
        }
        // Increment the current position i
        INCREMENT_I ( );
    }

    // Print the output string
    PRINT_RES ( );

    // Return 0 to indicate successful execution
    return 0;
}

