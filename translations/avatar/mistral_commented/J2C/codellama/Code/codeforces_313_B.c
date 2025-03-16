// Import necessary headers
#include <stdio.h>
#include <string.h>

// Initialize input and output streams
int main ( ) {
    FILE *br = stdin ;
    FILE *pw = stdout ;

    // Declare variables
    char *line = NULL ;
    size_t len = 0 ;
    ssize_t read ;

    // Read input from stdin
    while ( ( read = getline ( &line, &len, br ) ) != -1 ) {
        // Print output to stdout
        printf ( "%s", line ) ;
    }

    // Free memory
    free ( line ) ;

    // End of code
    return 0 ;
}

