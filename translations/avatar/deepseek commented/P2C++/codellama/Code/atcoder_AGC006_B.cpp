#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the calc function which processes a list x
int calc ( vector < int > x ) {
    // Define a nested sub function within calc for further processing
    auto sub = [ & ] ( vector < int > y , bool debug = false ) {
        // Print the current state of y if debug mode is on
        if ( debug ) {
            cout << "D " << y << endl;
        }
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while ( y.size () > 1 ) {
            y = vector < int > ( y.begin () + 1 , y.end () - 1 );
            sort ( y.begin () , y.end () );
            y = vector < int > ( y.begin () + 1 , y.end () - 1 );
            // Print the current state of y if debug mode is on
            if ( debug ) {
                cout << "D " << y << endl;
            }
        }
        // Return the final single element of y
        return y [ 0 ];
    };
    // Process the input list x using sub function
    vector < int > y = sub ( x );
    // Check if the final element of y is 2
    if ( y [ 0 ] == 2 ) {
        // Call sub again with debug mode on and print the result
        sub ( x , true );
        cout << "= " << x << endl;
    }
    // Return the first element of the final y
    return y [ 0 ];
}

// Check if X is 1 or N * 2 - 1, print "No" if true
if ( X == 1 or X == N * 2 - 1 ) {
    cout << "No" << endl;
} else {
    // Print "Yes" if X is not 1 or N * 2 - 1
    cout << "Yes" << endl;
    // Construct the list xs based on the value of X
    if ( X == N * 2 - 2 ) {
        xs = vector < int > ( N - 1 , X + 2 ) + vector < int > ( 1 , N - 1 );
    } else {
        ys = vector < int > ( 1 , X - 1 ) + vector < int > ( X + 3 , N * 2 );
        xs = ys.begin () + N - 3 , ys.end () + vector < int > ( X + 2 , X - 1 , X , X + 1 );
    }
    // Print each element of xs
    for ( int x : xs ) {
        cout << x << endl;
    }
}

