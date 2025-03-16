
// Importing necessary header files for file I/O and collections
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <cassert>
#include <iomanip>
#include <list>
#include <deque>
#include <complex>
#include <numeric>
#include <functional>
#include <utility>
#include <memory>
#include <locale>
#include <exception>
#include <typeinfo>

using namespace std;

// Main method is the entry point of the C++ application
int main ( ) {
    // Declaring a static variable named'sc' of istringstream class
    // to read input from the standard input stream
    istringstream sc ( "" ) ;

    // Reading the first integer 'n' from the standard input
    int n ;
    sc >> n ;

    // Reading the second integer'm' from the standard input
    int m ;
    sc >> m ;

    // Checking if 'n' is equal to zero
    if ( n == 0 ) {
        // If'm' is not equal to zero, print "Impossible"
        if ( m!= 0 ) {
            cout << "Impossible" << endl ;
        } else { // If'm' is also zero, print '0' space '0'
            cout << 0 << " " << 0 << endl ;
        }
        // Returning from the main method
        return 0 ;
    }

    // Checking if'm' is less than or equal to 'n'
    if ( m <= n ) {
        // If'm' is zero, assign it the value 1
        if ( m == 0 ) {
            m = 1 ;
        }
        // Printing 'n' and the sum of'm' and 'n' minus one
        cout << n << " " << ( m + n - 1 ) << endl ;
        // Returning from the main method
        return 0 ;
    }

    // If'm' is greater than 'n', print'm' and the sum of'm' and 'n' minus one
    cout << m << " " << ( m + n - 1 ) << endl ;
    // Returning from the main method
    return 0 ;
}
