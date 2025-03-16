
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    char t [ 4 ] [ 4 ]; // Initialize an empty 4x4 grid to store the input strings
    int black = 0, white = 0, correct = 0; // Initialize black and white counters to 0
    int i, j;
    
    for ( i = 0 ; i < 4 ; i++ ) { // Loop through 4 iterations to get input strings from user
        scanf ( "%s", t [ i ] );
    }
    
    for ( i = 0 ; i < 3 ; i++ ) { // Loop through the first 3 rows of the 4x4 grid represented by list 't'
        for ( j = 0 ; j < 3 ; j++ ) { // Loop through the first 3 columns of the current row
            if ( t [ i ] [ j ] == '#' ) { // If current cell contains '#', increment 'black' counter
                black++;
            } else { // If current cell contains '.', increment 'white' counter
                white++;
            }
            
            // Check the neighboring cells and increment 'black' or 'white' counter accordingly
            if ( t [ i ] [ j + 1 ] == '#' ) {
                black++;
            } else {
                white++;
            }
            
            if ( t [ i + 1 ] [ j ] == '#' ) {
                black++;
            } else {
                white++;
            }
            
            if ( t [ i + 1 ] [ j + 1 ] == '#' ) {
                black++;
            } else {
                white++;
            }
            
            // Check the current cell and its neighbors for winning conditions
            if ( ( black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 ) ) {
                correct = 1; // If a winning condition is met, set 'correct' to 1 and break out of the loop
                break;
            }
            
            // Reset black and white counters for the next iteration of the inner loop
            black = 0;
            white = 0;
        }
        
        if ( correct == 1 ) { // If 'correct' is set to 1, print 'YES'
            printf ( "YES\n" );
            break;
        }
    }
    
    if ( correct == 0 ) { // If 'correct' is not set to 1, print 'NO'
        printf ( "NO\n" );
    }
    
    return 0;
}

