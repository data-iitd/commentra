// Including necessary headers for file I/O and collections
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <cctype>
#include <bitset>
#include <deque>
#include <list>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <sys/time.h>
#include <fstream>
#include <limits>

// Defining a namespace to avoid conflicts
using namespace std ;

// Main method is the entry point of the C++ application
int main ( ) {
    // Declaring a variable named 'sc' of type 'ifstream'
    // to read input from the standard input stream
    ifstream sc ;

    // Reading the first integer 'n' from the standard input
    int n ;
    sc >> n ;

    // Reading the second integer 'm' from the standard input
    int m ;
    sc >> m ;

    // Checking if 'n' is equal to zero
    if ( n == 0 ) {
        // If 'm' is not equal to zero, print "Impossible"
        if ( m != 0 ) {
            cout << "Impossible" << endl ;
        } else { // If 'm' is also zero, print '0' space '0'
            cout << 0 << " " << 0 << endl ;
        }
        // Returning from the main method
        return 0 ;
    }

    // Checking if 'm' is less than or equal to 'n'
    if ( m <= n ) {
        // If 'm' is zero, assign it the value 1
        if ( m == 0 ) {
            m = 1 ;
        }
        // Printing 'n' and the sum of 'm' and 'n' minus one
        cout << n << " " << ( m + n - 1 ) << endl ;
        // Returning from the main method
        return 0 ;
    }

    // If 'm' is greater than 'n', print 'm' and the sum of 'm' and 'n' minus one
    cout << m << " " << ( m + n - 1 ) << endl ;
}

