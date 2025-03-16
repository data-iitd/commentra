#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main ( ) { 
    int h , w , n , sr , sc ; // Declare variables
    char s [ 100 ] , t [ 100 ] ; // Declare strings
    
    // Read input values
    scanf ( "%d %d %d %d %d" , & h , & w , & n , & sr , & sc ) ; 
    
    // Read the moves
    scanf ( "%s %s" , s , t ) ; 
    
    // Initialize variables to track safe bounds
    int usafe = 1 , dsafe = h , lsafe = 1 , rsafe = w ; 
    int end = 0 ; // Initialize end flag to 0
    
    // Process moves in reverse order for rows
    for ( int i = n - 1 ; i >= 0 ; i -- ) { 
        if ( s [ i ] == 'U' ) { 
            usafe ++ ; // Move up, increase upper safe bound
        } else if ( s [ i ] == 'D' ) { 
            dsafe -- ; // Move down, decrease lower safe bound
        } 
        if ( usafe > dsafe ) { // Check if upper safe bound exceeds lower safe bound
            end = 1 ; // Set end flag to 1 if unsafe
            break ; // Break out of the loop
        } 
        if ( i > 0 ) { // Check if it's not the first move
            if ( t [ i - 1 ] == 'U' ) { 
                dsafe = ( dsafe + 1 > h ) ? h : dsafe + 1 ; // Adjust lower safe bound if previous move was up
            } else if ( t [ i - 1 ] == 'D' ) { 
                usafe = ( usafe - 1 < 1 ) ? 1 : usafe - 1 ; // Adjust upper safe bound if previous move was down
            } 
        } 
    } 
    
    // Process moves in reverse order for columns
    for ( int i = n - 1 ; i >= 0 ; i -- ) { 
        if ( s [ i ] == 'L' ) { 
            lsafe ++ ; // Move left, increase left safe bound
        } else if ( s [ i ] == 'R' ) { 
            rsafe -- ; // Move right, decrease right safe bound
        } 
        if ( lsafe > rsafe ) { // Check if left safe bound exceeds right safe bound
            end = 1 ; // Set end flag to 1 if unsafe
            break ; // Break out of the loop
        } 
        if ( i > 0 ) { // Check if it's not the first move
            if ( t [ i - 1 ] == 'L' ) { 
                rsafe = ( rsafe + 1 > w ) ? w : rsafe + 1 ; // Adjust right safe bound if previous move was left
            } else if ( t [ i - 1 ] == 'R' ) { 
                lsafe = ( lsafe - 1 < 1 ) ? 1 : lsafe - 1 ; // Adjust left safe bound if previous move was right
            } 
        } 
    } 
    
    // Check if the final position is safe
    if ( sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && ! end ) { 
        printf ( "YES\n" ) ; // Output YES if safe
    } else { 
        printf ( "NO\n" ) ; // Output NO if not safe
    } 
    
    return 0 ; 
}

