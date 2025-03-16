// Read N and X from input
Scanner sc = new Scanner ( System.in );
int N = sc.nextInt ( );
int X = sc.nextInt ( );

// Import the permutations function from itertools
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// Define the calc function which processes a list x
public static int calc ( int [] x ) {
    // Define a nested sub function within calc for further processing
    int [] sub ( int [] y , boolean debug ) {
        // Print the current state of y if debug mode is on
        if ( debug ) {
            System.out.println ( "D" + Arrays.toString ( y ) );
        }
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while ( y.length > 1 ) {
            int [] z = new int [ y.length - 2 ];
            for ( int i = 0 ; i < y.length - 2 ; i ++ ) {
                z [ i ] = y [ i ] < y [ i + 1 ] ? y [ i + 1 ] : y [ i ];
            }
            y = z;
            // Print the current state of y if debug mode is on
            if ( debug ) {
                System.out.println ( "D" + Arrays.toString ( y ) );
            }
        }
        // Return the final single element of y
        return y;
    }
    // Process the input list x using sub function
    int [] y = sub ( x , false );
    // Check if the final element of y is 2
    if ( y [ 0 ] == 2 ) {
        // Call sub again with debug mode on and print the result
        sub ( x , true );
        System.out.println ( "=" + Arrays.toString ( x ) );
    }
    // Return the first element of the final y
    return y [ 0 ];
}

// Check if X is 1 or N * 2 - 1, print "No" if true
if ( X == 1 || X == N * 2 - 1 ) {
    System.out.println ( "No" );
} else {
    // Print "Yes" if X is not 1 or N * 2 - 1
    System.out.println ( "Yes" );
    // Construct the list xs based on the value of X
    if ( X == N * 2 - 2 ) {
        int [] xs = new int [ N - 1 + 2 ];
        for ( int i = 0 ; i < N - 1 ; i ++ ) {
            xs [ i ] = i + 1;
        }
        for ( int i = N - 1 ; i < N - 1 + 2 ; i ++ ) {
            xs [ i ] = i + 1;
        }
    } else {
        int [] ys = new int [ N * 2 ];
        for ( int i = 0 ; i < N * 2 ; i ++ ) {
            ys [ i ] = i + 1;
        }
        int [] xs = new int [ N - 3 + 5 ];
        for ( int i = 0 ; i < N - 3 ; i ++ ) {
            xs [ i ] = ys [ i ];
        }
        xs [ N - 3 ] = X + 2;
        xs [ N - 2 ] = X - 1;
        xs [ N - 1 ] = X;
        xs [ N ] = X + 1;
        for ( int i = N + 1 ; i < N - 3 + 5 ; i ++ ) {
            xs [ i ] = ys [ i - 4 ];
        }
    }
    // Print each element of xs
    for ( int x : xs ) {
        System.out.println ( x );
    }
}


Translate the above Java code to C++ and end with comment "