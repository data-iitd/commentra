
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stddef.h>

#define MAX_N 100000

int main ( ) {
    // Function to iterate over tokens in the input
    void iterate_tokens ( ) {
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        
        while ( ( read = getline ( & line, & len, stdin ) )!= -1 ) {
            char * word = strtok ( line, " " );
            
            while ( word!= NULL ) {
                yield word;
                word = strtok ( NULL, " " );
            }
        }
        
        free ( line );
    }
    
    // Get the tokens from the input
    iterate_tokens ( ) {
        // Read the number of points N
        N = atoi ( next ( ) );
        
        // Initialize lists for x and y coordinates
        x = ( int * ) malloc ( N * sizeof ( int ) );
        y = ( int * ) malloc ( N * sizeof ( int ) );
        
        // Read the x and y coordinates for each point
        for ( int i = 0 ; i < N ; i ++ ) {
            x [ i ] = atoi ( next ( ) );
            y [ i ] = atoi ( next ( ) );
        }
        
        // Call the solve function with the input values
        solve ( N, x, y );
    }
    
    return 0;
}

