
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Read the dimensions of the grid and the number of operations
    int n , m ;
    scanf ( "%d %d" , & n , & m ) ;
    
    // Initialize a count grid with all elements set to 0
    int ** count = ( int ** ) malloc ( n * sizeof ( int * ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        count [ i ] = ( int * ) malloc ( n * sizeof ( int ) ) ;
        for ( int j = 0 ; j < n ; j ++ ) {
            count [ i ] [ j ] = 0 ;
        }
    }
    
    // Initialize the answer to -1
    int ans = - 1 ;
    
    // Loop through each operation
    for ( int k = 0 ; k < m ; k ++ ) {
        // Read the coordinates of the operation
        int x , y ;
        scanf ( "%d %d" , & x , & y ) ;
        
        // Adjust the coordinates to zero-based index
        x -= 1 ;
        y -= 1 ;
        
        // Flag to check if a cell in the 3x3 grid reaches a count of 9
        int found = 0 ;
        
        // Check the 3x3 grid centered at (x, y)
        for ( int i = x - 2 ; i <= x + 1 ; i ++ ) {
            for ( int j = y - 2 ; j <= y + 1 ; j ++ ) {
                if ( i >= 0 && i < n && j >= 0 && j < n ) {
                    count [ i ] [ j ] += 1 ;
                    if ( count [ i ] [ j ] == 9 ) {
                        found = 1 ;
                    }
                }
            }
        }
        
        // If a cell in the 3x3 grid reaches a count of 9, update ans and break
        if ( found ) {
            ans = k + 1 ;
            break ;
        }
    }
    
    // Print the result
    printf ( "%d\n" , ans ) ;
    
    // Free the memory
    for ( int i = 0 ; i < n ; i ++ ) {
        free ( count [ i ] ) ;
    }
    free ( count ) ;
    
    return 0 ;
}

