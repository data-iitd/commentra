
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the calc function which processes a vector x
int calc ( vector < int > & x ) {
    // Define a nested sub function within calc for further processing
    function < int ( vector < int > & y, int debug = 0 ) > sub = [&] ( vector < int > & y, int debug = 0 ) -> int {
        // Print the current state of y if debug mode is on
        if ( debug ) {
            cout << "D " ;
            for ( auto & e : y ) {
                cout << e << " " ;
            }
            cout << endl ;
        }
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while ( y.size ( ) > 1 ) {
            vector < int > z ;
            for ( int i = 0 ; i < y.size ( ) - 2 ; i ++ ) {
                vector < int > t = { y [ i ], y [ i + 1 ], y [ i + 2 ] } ;
                sort ( t.begin ( ), t.end ( ) ) ;
                z.push_back ( t [ 1 ] ) ;
            }
            y = z ;
            // Print the current state of y if debug mode is on
            if ( debug ) {
                cout << "D " ;
                for ( auto & e : y ) {
                    cout << e << " " ;
                }
                cout << endl ;
            }
        }
        // Return the final single element of y
        return y [ 0 ] ;
    } ;
    // Process the input vector x using sub function
    vector < int > y = x ;
    int r = sub ( y ) ;
    // Check if the final element of y is 2
    if ( r == 2 ) {
        // Call sub again with debug mode on and print the result
        sub ( x, 1 ) ;
        cout << "=" ;
        for ( auto & e : x ) {
            cout << " " << e ;
        }
        cout << endl ;
    }
    // Return the first element of the final y
    return r ;
}

int main ( ) {
    int N, X ;
    cin >> N >> X ;
    // Construct the vector xs based on the value of X
    vector < int > xs ;
    if ( X == N * 2 - 2 ) {
        for ( int i = N - 1 ; i <= X + 1 ; i ++ ) {
            xs.push_back ( i ) ;
        }
    } else {
        vector < int > ys ;
        for ( int i = 1 ; i <= X - 1 ; i ++ ) {
            ys.push_back ( i ) ;
        }
        for ( int i = X + 3 ; i <= N * 2 ; i ++ ) {
            ys.push_back ( i ) ;
        }
        xs = ys ;
        xs.erase ( xs.begin ( ) + N - 3, xs.begin ( ) + N - 1 ) ;
        xs.insert ( xs.begin ( ) + N - 3, X + 2 ) ;
        xs.insert ( xs.begin ( ) + N - 2, X - 1 ) ;
        xs.insert ( xs.begin ( ) + N - 1, X ) ;
        xs.insert ( xs.begin ( ) + N, X + 1 ) ;
    }
    // Print each element of xs
    for ( auto & e : xs ) {
        cout << e << endl ;
    }
    return 0 ;
}

