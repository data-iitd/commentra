
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int h , w , n , sr , sc , usafe , dsafe , lsafe , rsafe , end ;  // Declaring necessary variables
    char s [ ] , t [ ] ;  // Declaring two character arrays to store the sequences of 'U' and 'D' and 'L' and 'R'

    scanf ( "%d %d %d" , & h , & w , & n ) ;  // Reading the height, width, and number of steps from the console
    scanf ( "%d %d" , & sr , & sc ) ;  // Reading the starting row and column of the safe zone from the console

    scanf ( "%s" , s ) ;  // Reading the sequence of 'U' and 'D' representing the up and down movements
    scanf ( "%s" , t ) ;  // Reading the sequence of 'L' and 'R' representing the left and right movements

    usafe = 1 ;  // Initializing two variables to keep track of the upper and lower boundaries of the safe zone
    dsafe = h ;

    // The first for loop is to check the vertical boundaries of the safe zone based on the sequence 's'
    for ( int i = n - 1 ; i >= 0 ; i -- ) {
        if ( s [ i ] == 'U' ) {  // If the current character in the sequence 's' is 'U', increase the upper boundary by 1
            usafe ++ ;
        } else if ( s [ i ] == 'D' ) {  // If the current character in the sequence 's' is 'D', decrease the lower boundary by 1
            dsafe -- ;
        }
        if ( usafe > dsafe ) {  // If the upper boundary is greater than the lower boundary, the safe zone is not valid
            end = 1 ;
            break ;
        }
        if ( i > 0 ) {  // If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
            if ( t [ i - 1 ] == 'U' ) {
                dsafe = dsafe + 1 < h ? dsafe + 1 : h ;  // If the previous character is 'U', increase the lower boundary by 1 to the minimum of the height
            } else if ( t [ i - 1 ] == 'D' ) {
                usafe = usafe - 1 > 1 ? usafe - 1 : 1 ;  // If the previous character is 'D', decrease the upper boundary by 1 to the maximum of 1
            }
        }
    }

    lsafe = 1 ;  // Initializing two variables to keep track of the left and right boundaries of the safe zone
    rsafe = w ;

    // The second for loop is to check the horizontal boundaries of the safe zone based on the sequence 't'
    for ( int i = n - 1 ; i >= 0 ; i -- ) {
        if ( s [ i ] == 'L' ) {  // If the current character in the sequence 's' is 'L', increase the left boundary by 1
            lsafe ++ ;
        } else if ( s [ i ] == 'R' ) {  // If the current character in the sequence 's' is 'R', decrease the right boundary by 1
            rsafe -- ;
        }
        if ( lsafe > rsafe ) {  // If the left boundary is greater than the right boundary, the safe zone is not valid
            end = 1 ;
            break ;
        }
        if ( i > 0 ) {  // If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
            if ( t [ i - 1 ] == 'L' ) {
                rsafe = rsafe + 1 < w ? rsafe + 1 : w ;  // If the previous character is 'L', increase the right boundary by 1 to the minimum of the width
            } else if ( t [ i - 1 ] == 'R' ) {
                lsafe = lsafe - 1 > 1 ? lsafe - 1 : 1 ;  // If the previous character is 'R', decrease the left boundary by 1 to the maximum of 1
            }
        }
    }

    if ( sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && ! end ) {  // Checking if the starting position of the safe zone is within the safe zone boundaries and the safe zone is valid
        printf ( "YES\n" ) ;
    } else {
        printf ( "NO\n" ) ;
    }

    return 0 ;
}

