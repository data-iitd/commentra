
// Importing the required utility class ios_base::sync_with_stdio(false) from the C++ standard library
#include <bits/stdc++.h>
using namespace std ;

// Main method is the entry point of the C++ application
int main ( ) {

    // Disabling synchronization between C and C++ standard input and output streams
    ios_base::sync_with_stdio ( false ) ;

    // Creating a new cin object to read input from the standard input stream
    cin.tie ( NULL ) ;

    // Creating a new cout object to write output to the standard output stream
    cout.tie ( NULL ) ;

    // Reading the first integer input n from the user
    int n ;
    cin >> n ;

    // Reading the second integer input m from the user
    int m ;
    cin >> m ;

    // Creating an integer array arr of size n to store the input integers
    int arr [ n ] ;

    // Creating an integer array gen of size 11 to store the count of each integer occurrence
    int gen [ 11 ] ;

    // Reading the input integers and storing them in the arr array
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> arr [ i ] ;
        // Incrementing the count of the arr[i] in the gen array
        gen [ arr [ i ] ] ++ ;
    }

    // Calculating the answer
    long long ans = 0 ;
    for ( int i = 1 ; i <= m ; i ++ ) {
        for ( int k = 1 ; k <= m ; k ++ ) {
            // Skipping the case when i and k are equal to avoid double counting
            if ( i!= k ) {
                // Multiplying the count of i and k and adding it to the answer
                ans += ( long long ) gen [ i ] * gen [ k ] ;
            }
        }
    }

    // Printing the answer divided by 2
    cout << ans / 2 << endl ;

    // Ending the C++ application
    return 0 ;
}
