
#include <bits/stdc++.h>
using namespace std ;

int main ( ) {
    // Creating a Scanner object for reading input from the standard input
    cin >> ws ;
    cin.sync ( ) ;
    cin.exceptions ( ) ;
    Scanner in = cin ;

    // Creating a PrintWriter object for writing output to the standard output
    cout << fixed << setprecision ( 1 ) ;
    cout.sync_with_stdio ( false ) ;
    cout.exceptions ( ) ;
    PrintWriter pw = cout ;

    // Reading two integers 'a' and 'b' from the standard input
    int a, b ;
    cin >> a >> b ;

    // Initializing variable 'c' to 0
    int c = 0 ;

    // Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if ( a == 1 && b == 1 ) {
        pw << 0 << endl ;  // Printing 0 as the output
        return 0 ;
    }

    // If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
    else {
        // Performing the loop until either 'a' or 'b' becomes 0
        while ( a >= 1 || b >= 1 ) {
            // If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if ( a >= b ) {
                b++ ;
                a -= 2 ;
            }
            // If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else {
                a++ ;
                b-- ;
            }

            // Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if ( a <= 0 || b <= 0 ) {
                c++ ;
                break ;
            }

            // Incrementing 'c' for each iteration of the loop
            c++ ;
        }

        // Printing the final result 'c' as the output
        pw << c << endl ;
    }

    // Closing the PrintWriter object
    pw.close ( ) ;

    return 0 ;
}

