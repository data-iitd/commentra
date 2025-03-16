
#include <bits/stdc++.h> 
using namespace std ; 
// Import necessary libraries.

int main ( ) { 
    ios_base :: sync_with_stdio ( false ) ; 
    cin.tie ( 0 ) ; 
    // Disable I/O synchronization.

    int t ; 
    cin >> t ; 
    // Read the number of test cases.

    while ( t -- ) { 
        int n ; 
        cin >> n ; 
        // Read the number of strings.

        long long [ ] cnt = new long long [ 5 ] ; 
        for ( int i = 0 ; i < 5 ; ++ i ) { 
            cnt [ i ] = 0 ; 
        } 
        // Initialize the count array.

        for ( int i = 0 ; i < n ; ++ i ) { 
            string str ; 
            cin >> str ; 
            if ( str [ 0 ] == 'M' ) { 
                cnt [ 0 ] ++ ; 
            } else if ( str [ 0 ] == 'A' ) { 
                cnt [ 1 ] ++ ; 
            } else if ( str [ 0 ] == 'R' ) { 
                cnt [ 2 ] ++ ; 
            } else if ( str [ 0 ] == 'C' ) { 
                cnt [ 3 ] ++ ; 
            } else if ( str [ 0 ] == 'H' ) { 
                cnt [ 4 ] ++ ; 
            } 
            // Count the occurrences of each character at the start of the strings.
        } 

        long long res = cnt [ 0 ] * cnt [ 1 ] * cnt [ 2 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 2 ] * cnt [ 3 ] * cnt [ 4 ] ; 
        cout << res << endl ; 
        // Calculate the number of combinations and print the result.
    } 

    return 0 ; 
}

