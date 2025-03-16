
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_BUFFER 1000000

// Reads a line from stdin and returns a pointer to it
char *read_line ( ) {
    char *line = ( char * ) malloc ( INPUT_BUFFER * sizeof ( char ) );
    fgets ( line , INPUT_BUFFER , stdin );
    return line;
}

// Reads an integer from stdin
int read_int ( ) {
    char *line = read_line ( );
    int value = atoi ( line );
    free ( line );
    return value;
}

// Reads a float from stdin
float read_float ( ) {
    char *line = read_line ( );
    float value = atof ( line );
    free ( line );
    return value;
}

// Reads a string from stdin
char *read_string ( ) {
    char *line = read_line ( );
    line [ strlen ( line ) - 1 ] = '\0';
    return line;
}

// Reads a line from stdin and returns a pointer to it
char *read_line ( ) {
    char *line = ( char * ) malloc ( INPUT_BUFFER * sizeof ( char ) );
    fgets ( line , INPUT_BUFFER , stdin );
    return line;
}

// Reads an integer from stdin
int read_int ( ) {
    char *line = read_line ( );
    int value = atoi ( line );
    free ( line );
    return value;
}

// Reads a float from stdin
float read_float ( ) {
    char *line = read_line ( );
    float value = atof ( line );
    free ( line );
    return value;
}

// Reads a string from stdin
char *read_string ( ) {
    char *line = read_line ( );
    line [ strlen ( line ) - 1 ] = '\0';
    return line;
}

int main ( ) {
    // Read the number of elements
    int n = read_int ( );

    // Initialize variables to track the best candidate interval
    int id = 0;
    int l = read_int ( );
    int r = read_int ( );

    // Process each interval
    for ( int i = 1 ; i < n ; i++ ) {
        int li = read_int ( );
        int ri = read_int ( );

        // Check if the current interval completely covers the best candidate interval
        if ( li <= l && r <= ri ) id = i;

        // Check if the current interval overlaps with the best candidate interval
        else if ( li < l || r < ri ) id = n;

        // Update the boundaries of the best candidate interval
        l = min ( l , li );
        r = max ( r , ri );
    }

    // Output the result
    printf ( "%d\n" , - 1 if id == n else id + 1 );

    return 0;
}

