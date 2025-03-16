
#include <bits/stdc++.h>

using namespace std;

int main ( ) {
    int n, m ;
    cin >> n >> m ;
    // Read two integers n and m from input

    int sa = 0 ;
    // Initialize sa to 0

    for ( int i = 0 ; i < n ; i++ ) {
        if ( cin.get ( ) == '-' ) {
            sa++ ;
        }
    }
    // Count the number of '-' characters in the input

    sa = min ( n - sa, sa ) ;
    // Set sa to the minimum of n - sa and sa, possibly normalizing sa

    vector < string > ss ;
    // Initialize an empty list to store results

    for ( int i = 0 ; i < m ; i++ ) {
        int a, b ;
        cin >> a >> b ;
        // Read two integers a and b in each iteration of the loop

        b -= a ;
        // Subtract a from b

        if ( b % 2 and b <= sa << 1 ) {
            ss.push_back ( "1\n" ) ;
            // Append "1\n" to ss if condition is met
        }
        else {
            ss.push_back ( "0\n" ) ;
            // Append "0\n" to ss otherwise
    }

    for ( int i = 0 ; i < ss.size ( ) ; i++ ) {
        cout << ss[i] ;
    }
    // Join and print the contents of ss

    return 0 ;
}

