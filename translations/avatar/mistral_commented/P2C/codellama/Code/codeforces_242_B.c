#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define lambda functions for reading input
int *I ( ) {
    int *arr = malloc ( 100 * sizeof ( int ) );
    int i = 0;
    char *line = NULL;
    size_t len = 0;
    while ( getline ( &line , &len , stdin ) != -1 ) {
        arr[i++] = atoi ( line );
    }
    return arr;
}

char *IS ( ) {
    char *line = NULL;
    size_t len = 0;
    getline ( &line , &len , stdin );
    return line;
}

int IN ( ) {
    char *line = NULL;
    size_t len = 0;
    getline ( &line , &len , stdin );
    return atoi ( line );
}

float IF ( ) {
    char *line = NULL;
    size_t len = 0;
    getline ( &line , &len , stdin );
    return atof ( line );
}

int main ( ) {
    // Read the number of test cases
    int n = IN ( );

    // Initialize id variable to 0
    int id = 0;

    // Read left and right boundary values for the first test case
    int l = IN ( );
    int r = IN ( );

    // Iterate through the remaining test cases
    for ( int i = 1 ; i < n ; i++ ) {
        // Read left and right boundary values for the current test case
        int li = IN ( );
        int ri = IN ( );

        // Check if the current test case overlaps with the previously defined boundary values
        if ( li <= l && r <= ri ) {
            // Update id variable to the index of the current test case
            id = i;
        }

        // If the current test case does not overlap, keep id as n
        else if ( li < l || r < ri ) {
            id = n;
        }

        // Update boundary values based on the current test case
        l = min ( l , li );
        r = max ( r , ri );
    }

    // Print the index of the test case that satisfies the condition, or -1 if no such test case exists
    printf ( "%d\n" , -1 if id == n else id + 1 );

    return 0;
}

