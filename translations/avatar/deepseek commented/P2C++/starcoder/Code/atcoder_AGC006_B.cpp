#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ( ) {
    // Read N and X from input
    int N, X;
    cin >> N >> X;

    // Define the calc function which processes a list x
    int calc ( vector < int > x ) {
        // Define a nested sub function within calc for further processing
        int sub ( vector < int > y, bool debug = 0 ) {
            // Print the current state of y if debug mode is on
            if ( debug ) {
                for ( int i = 0 ; i < y.size ( ) ; i++ ) {
                    cout << "D" << y [ i ] << " ";
                }
                cout << endl;
            }
            // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
            while ( y.size ( ) > 1 ) {
                for ( int i = 0 ; i < y.size ( ) - 2 ; i++ ) {
                    y [ i ] = ( y [ i ] + y [ i + 1 ] + y [ i + 2 ] ) / 2;
                }
                // Print the current state of y if debug mode is on
                if ( debug ) {
                    for ( int i = 0 ; i < y.size ( ) ; i++ ) {
                        cout << "D" << y [ i ] << " ";
                    }
                    cout << endl;
                }
            }
            // Return the final single element of y
            return y [ 0 ];
        }
        // Process the input list x using sub function
        int y = sub ( x );
        // Check if the final element of y is 2
        if ( y == 2 ) {
            // Call sub again with debug mode on and print the result
            sub ( x, 1 );
            for ( int i = 0 ; i < x.size ( ) ; i++ ) {
                cout << x [ i ] << " ";
            }
            cout << endl;
        }
        // Return the first element of the final y
        return y;
    }

    // Check if X is 1 or N * 2 - 1, print "No" if true
    if ( X == 1 || X == N * 2 - 1 ) {
        cout << "No" << endl;
    } else {
        // Print "Yes" if X is not 1 or N * 2 - 1
        cout << "Yes" << endl;
        // Construct the list xs based on the value of X
        vector < int > xs;
        if ( X == N * 2 - 2 ) {
            for ( int i = N - 1 ; i <= X + 2 ; i++ ) {
                xs.push_back ( i );
            }
            for ( int i = 1 ; i <= N - 1 ; i++ ) {
                xs.push_back ( i );
            }
        } else {
            vector < int > ys;
            for ( int i = 1 ; i <= X - 1 ; i++ ) {
                ys.push_back ( i );
            }
            for ( int i = X + 3 ; i <= N * 2 ; i++ ) {
                ys.push_back ( i );
            }
            for ( int i = 0 ; i < N - 3 ; i++ ) {
                xs.push_back ( ys [ i ] );
            }
            xs.push_back ( X + 2 );
            xs.push_back ( X - 1 );
            xs.push_back ( X );
            xs.push_back ( X + 1 );
            for ( int i = N - 3 ; i < ys.size ( ) ; i++ ) {
                xs.push_back ( ys [ i ] );
            }
        }
        // Print each element of xs
        for ( int i = 0 ; i < xs.size ( ) ; i++ ) {
            cout << xs [ i ] << " ";
        }
    }

    // Return 0
    return 0;
}

