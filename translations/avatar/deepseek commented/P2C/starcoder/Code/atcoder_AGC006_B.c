#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    // Read N and X from input
    int N, X;
    scanf ( "%d %d", &N, &X );

    // Define the calc function which processes a list x
    int calc ( int * x, int debug ) {
        // Define a nested sub function within calc for further processing
        int sub ( int * y, int debug ) {
            // Print the current state of y if debug mode is on
            if ( debug ) {
                for ( int i = 0 ; i < N ; i ++ ) {
                    printf ( "D %d ", y [ i ] );
                }
                printf ( "\n" );
            }
            // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
            while ( y [ N - 1 ]!= 2 ) {
                for ( int i = 0 ; i < N - 2 ; i ++ ) {
                    y [ i ] = ( y [ i ] + y [ i + 1 ] + y [ i + 2 ] ) / 2;
                }
                // Print the current state of y if debug mode is on
                if ( debug ) {
                    for ( int i = 0 ; i < N ; i ++ ) {
                        printf ( "D %d ", y [ i ] );
                    }
                    printf ( "\n" );
                }
            }
            // Return the final single element of y
            return y [ 0 ];
        }
        // Process the input list x using sub function
        int * y = ( int * ) malloc ( N * sizeof ( int ) );
        for ( int i = 0 ; i < N ; i ++ ) {
            y [ i ] = x [ i ];
        }
        int result = sub ( y, debug );
        // Check if the final element of y is 2
        if ( y [ 0 ] == 2 ) {
            // Call sub again with debug mode on and print the result
            sub ( y, 1 );
            printf ( "= %d\n", result );
        }
        // Return the first element of the final y
        return result;
    }

    // Check if X is 1 or N * 2 - 1, print "No" if true
    if ( X == 1 || X == N * 2 - 1 ) {
        printf ( "No\n" );
    } else {
        // Print "Yes" if X is not 1 or N * 2 - 1
        printf ( "Yes\n" );
        // Construct the list xs based on the value of X
        int * xs = ( int * ) malloc ( N * sizeof ( int ) );
        if ( X == N * 2 - 2 ) {
            for ( int i = N - 1 ; i < X + 2 ; i ++ ) {
                xs [ i - N + 1 ] = i;
            }
            for ( int i = 1 ; i < N - 1 ; i ++ ) {
                xs [ i + N - 3 ] = i;
            }
        } else {
            int * ys = ( int * ) malloc ( N * sizeof ( int ) );
            for ( int i = 1 ; i < X - 1 ; i ++ ) {
                ys [ i - 1 ] = i;
            }
            for ( int i = X + 3 ; i < N * 2 ; i ++ ) {
                ys [ i - X - 3 ] = i;
            }
            for ( int i = 0 ; i < N - 3 ; i ++ ) {
                xs [ i ] = ys [ i ];
            }
            xs [ N - 3 ] = X + 2;
            xs [ N - 2 ] = X - 1;
            xs [ N - 1 ] = X;
            xs [ N - 0 ] = X + 1;
            for ( int i = N - 3 ; i < N ; i ++ ) {
                xs [ i + 1 ] = ys [ i ];
            }
        }
        // Print each element of xs
        for ( int i = 0 ; i < N ; i ++ ) {
            printf ( "%d\n", xs [ i ] );
        }
    }
    // Return 0
    return 0;
}

