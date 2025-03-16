#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the calc function which processes a list x
int calc ( int * x , int n ) {
    // Define a nested sub function within calc for further processing
    int sub ( int * y , int n , int debug ) {
        // Print the current state of y if debug mode is on
        if ( debug ) {
            printf ( "D" );
            for ( int i = 0 ; i < n ; i ++ ) {
                printf ( " %d" , y [ i ] );
            }
            printf ( "\n" );
        }
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while ( n > 1 ) {
            for ( int i = 0 ; i < n - 2 ; i ++ ) {
                y [ i ] = ( y [ i ] < y [ i + 1 ] ) ? ( y [ i ] < y [ i + 2 ] ? y [ i + 1 ] : y [ i + 2 ] ) : ( y [ i + 1 ] < y [ i + 2 ] ? y [ i + 1 ] : y [ i + 2 ] );
            }
            // Print the current state of y if debug mode is on
            if ( debug ) {
                printf ( "D" );
                for ( int i = 0 ; i < n ; i ++ ) {
                    printf ( " %d" , y [ i ] );
                }
                printf ( "\n" );
            }
            n --;
        }
        // Return the final single element of y
        return y [ 0 ];
    }
    // Process the input list x using sub function
    int y = sub ( x , n , 0 );
    // Check if the final element of y is 2
    if ( y == 2 ) {
        // Call sub again with debug mode on and print the result
        sub ( x , n , 1 );
        printf ( "=" );
        for ( int i = 0 ; i < n ; i ++ ) {
            printf ( " %d" , x [ i ] );
        }
        printf ( "\n" );
    }
    // Return the first element of the final y
    return y;
}

int main ( void ) {
    // Read N and X from input
    int n , x;
    scanf ( "%d %d" , & n , & x );

    // Check if X is 1 or N * 2 - 1, print "No" if true
    if ( x == 1 || x == n * 2 - 1 ) {
        printf ( "No\n" );
    } else {
        // Print "Yes" if X is not 1 or N * 2 - 1
        printf ( "Yes\n" );
        // Construct the list xs based on the value of X
        if ( x == n * 2 - 2 ) {
            int xs [ n - 1 ] = { 0 };
            for ( int i = 0 ; i < n - 1 ; i ++ ) {
                xs [ i ] = n - 1 - i;
            }
            for ( int i = 0 ; i < n - 1 ; i ++ ) {
                printf ( "%d " , xs [ i ] );
            }
            printf ( "\n" );
        } else {
            int ys [ n * 2 - 3 ] = { 0 };
            for ( int i = 0 ; i < n * 2 - 3 ; i ++ ) {
                ys [ i ] = i + 1;
            }
            int xs [ n - 3 ] = { 0 };
            for ( int i = 0 ; i < n - 3 ; i ++ ) {
                xs [ i ] = ys [ i ];
            }
            xs [ n - 3 ] = x + 2;
            xs [ n - 2 ] = x - 1;
            xs [ n - 1 ] = x;
            xs [ n ] = x + 1;
            for ( int i = 0 ; i < n - 3 ; i ++ ) {
                printf ( "%d " , xs [ i ] );
            }
            printf ( "\n" );
        }
    }

    return 0;
}

