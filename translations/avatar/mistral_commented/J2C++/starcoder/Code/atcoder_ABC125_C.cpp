#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
#include <utility>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cassert>

using namespace std;

// Initialize the array A and read its elements from the standard input
int A [ ] ;

int main ( ) {
    int N ;
    cin >> N ; // Read the number of elements in the array A
    A = new int [ N ] ; // Allocate memory for the array A of size N

    // Read the elements of the array A from the standard input
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> A [ i ] ;
    }

    // Initialize arrays M, L, and R
    int M [ N ] ;
    int L [ N ] ;
    int R [ N ] ;

    // Initialize the first elements of L and R arrays
    L [ 0 ] = A [ 0 ] ;
    R [ N - 1 ] = A [ N - 1 ] ;

    // Calculate the gcd of consecutive pairs of elements in the array A,
    // starting from the second element, and store the results in the L array
    for ( int i = 1 ; i < N ; i ++ ) {
        L [ i ] = gcd ( L [ i - 1 ], A [ i ] ) ;
    }

    // Calculate the gcd of consecutive pairs of elements in the array A,
    // starting from the last element, and store the results in the R array
    for ( int i = N - 2 ; i >= 0 ; i -- ) {
        R [ i ] = gcd ( R [ i + 1 ], A [ i ] ) ;
    }

    // Find the maximum value among the gcd of consecutive pairs of elements
    // in the subarrays [0, i] and [i+1, N-1] for all i from 0 to N-2
    int answer = max ( L [ N - 2 ], R [ 1 ] ) ;
    for ( int i = 1 ; i < N - 1 ; i ++ ) {
        answer = max ( answer, gcd ( L [ i - 1 ], R [ i + 1 ] ) ) ;
    }

    // Print the result
    cout << answer << endl ;

    return 0 ;
}

// Calculate the greatest common divisor of two integers using Euclid's algorithm
int gcd ( int a, int b ) {
    int tmp ;

    // If b is greater than a, swap a and b
    if ( b > a ) {
        tmp = a ;
        a = b ;
        b = tmp ;
    }

    // If b is zero, return a as the gcd
    if ( b == 0 ) {
        return a ;
    }

    // Calculate the remainder of the division of a by b, and repeat the process
    int r = - 1 ;
    do {
        r = a % b ;
        a = b ;
        b = r ;
    } while ( r!= 0 ) ;

    // Return the final result
    return a ;
}

