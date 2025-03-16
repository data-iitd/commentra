

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ( ) {
    int n;
    cin >> n;
    // Read the number of elements from input

    vector < int > a ( n );
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a [ i ];
        // Read the list elements from input
    }

    if ( accumulate ( a. begin ( ), a. end ( ), 0 ) % ( n * ( n + 1 ) / 2 ) ) {
        // Check if the sum of the list is divisible by the triangular number (n * (n + 1) / 2)
        cout << "NO" << endl;
        // Print "NO"
    } else {
        int k = accumulate ( a. begin ( ), a. end ( ), 0 ) / ( n * ( n + 1 ) / 2 );
        // Calculate the quotient k by dividing the sum of the list by the triangular number

        a. push_back ( a [ 0 ] );
        // Append the first element to the end of the list to create a circular list

        if ( accumulate ( a. begin ( ) + 1, a. end ( ), 0, plus < int > ( ), [ & ] ( int i, int j ) { return ( k - i + j ) % n; } ) or accumulate ( a. begin ( ) + 1, a. end ( ), 0, plus < int > ( ), [ & ] ( int i, int j ) { return ( k - i + j ) / n >= 0; } )!= n ) {
            // Check if the condition is met for all elements in the circular list
            cout << "NO" << endl;
            // Print "NO"
        } else {
            cout << "YES" << endl;
            // If the condition is met, print "YES"
        }
    }

    return 0;
}
