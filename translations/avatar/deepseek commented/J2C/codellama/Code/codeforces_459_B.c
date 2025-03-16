#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv [ ] ) { 
    // Read the size of the array
    int N ; 
    scanf ( "%d", &N ) ; 

    // Read the elements of the array
    int *A = ( int * ) malloc ( N * sizeof ( int ) ) ; 
    for ( int n = 0 ; n < N ; n ++ ) { 
        scanf ( "%d", &A [ n ] ) ; 
    }

    // Sort the array
    qsort ( A, N, sizeof ( int ), compare ) ; 

    // Find the minimum and maximum values in the array
    int min = A [ 0 ] ; 
    int max = A [ N - 1 ] ; 

    // Count the occurrences of the minimum and maximum values
    long mins = 0 ; 
    long maxs = 0 ; 
    for ( int n = 0 ; n < N ; n ++ ) { 
        if ( A [ n ] == min ) mins ++ ; 
        if ( A [ n ] == max ) maxs ++ ; 
    }

    // Special case: if min == max
    if ( min == max ) { 
        printf ( "%ld %ld\n", ( max - min ), mins * ( mins - 1 ) / 2 ) ; 
    } else { 
        // General case: if min != max
        printf ( "%ld %ld\n", ( max - min ), mins * maxs ) ; 
    }

    // Free the memory allocated for the array
    free ( A ) ; 

    return 0 ; 
}

// Compare function for qsort
int compare ( const void *a, const void *b ) { 
    return ( *( int * ) a - *( int * ) b ) ; 
}

// Debugging method to print debug statements
void debug ( char *format, ... ) { 
    va_list args ; 
    va_start ( args, format ) ; 
    vfprintf ( stderr, format, args ) ; 
    va_end ( args ) ; 
}

