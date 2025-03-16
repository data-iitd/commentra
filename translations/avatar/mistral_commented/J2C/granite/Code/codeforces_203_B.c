
#include <stdio.h>  // Include the standard input/output library for C

int main ( void ) {
    int N, M, x, y, xx, yy, black [ 1001 ] [ 1001 ] = { 0 } ;  // Declare and initialize the necessary variables and arrays
    
    scanf ( "%d %d", &N, &M ) ;  // Read the first two integers from the input, which represent the size of the grid and the number of stones to be placed
    
    for ( int m = 1 ; m <= M ; m ++ ) {  // Iterate M times, once for each stone to be placed
        scanf ( "%d %d", &x, &y ) ;  // Read the x-coordinate and y-coordinate of the next stone to be placed
        
        for ( xx = x - 1 ; xx <= x + 1 ; xx ++ ) {  // Iterate over all the neighboring cells in the x-direction
            for ( yy = y - 1 ; yy <= y + 1 ; yy ++ ) {  // Iterate over all the neighboring cells in the y-direction
                if ( ++ black [ xx ] [ yy ] == 9 ) {  // Check if the number of black cells around this cell becomes 9
                    printf ( "%d\n", m ) ;  // If so, print the index of the stone that caused this condition and return
                    return 0 ;
                }
            }
        }
    }
    
    printf ( "-1\n" ) ;  // If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return
    
    return 0 ;  // End the program
}
