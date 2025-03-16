
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, a [ ], k = 0 ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
        cin >> a [ i ] ;
    if ( accumulate ( a, a + n, 0 ) % ( n * ( n + 1 ) / 2 ) ) {
        // Check if the sum of the list is divisible by the triangular number (n * (n + 1) / 2)
        cout << "NO" << endl ;
    } else {
        k = accumulate ( a, a + n, 0 ) / ( n * ( n + 1 ) / 2 ) ;
        // Calculate the quotient k by dividing the sum of the list by the triangular number
        a [ n ] = a [ 0 ] ;
        // Append the first element to the end of the list to create a circular list
        if ( accumulate ( a + 1, a + n + 1, 0 ) % n || accumulate ( a + 1, a + n + 1, 0 ) / n >= 0 ) {
            // Check if the condition is met for all elements in the circular list
            cout << "NO" << endl ;
        } else {
            cout << "YES" << endl ;
            // If the condition is met, print "YES"
        }
    }
    return 0 ;
}

