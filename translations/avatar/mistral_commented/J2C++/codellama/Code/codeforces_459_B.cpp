
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <climits>
#include <array>

using namespace std;

int main ( ) {
    int N ; // Declare an integer variable N to store the number of elements
    cin >> N ; // Read the number of elements N from the standard input
    int A [ N ] ; // Declare an integer array A of size N to store the elements

    // Use a for loop to read each element from the standard input and store it in the corresponding index of the array A
    for ( int n = 0 ; n < N ; n ++ ) {
        cin >> A [ n ] ;
    }

    // Use the sort() function to sort the elements in the array A in ascending order
    sort ( A , A + N ) ;

    // Initialize two variables, min and max, to store the minimum and maximum elements in the array A, respectively
    int min = A [ 0 ] ;
    int max = A [ N - 1 ] ;

    // Use a for-each loop to iterate through each element in the array A and perform some checks
    for ( int value : A ) {
        if ( value == min ) { // If the current element is equal to the minimum element min, increment the variable mins by 1
            mins ++ ;
        }
        if ( value == max ) { // If the current element is equal to the maximum element max, increment the variable maxs by 1
            maxs ++ ;
        }
    }

    // Check if the minimum and maximum elements are the same
    if ( min == max ) {
        long result = ( max - min ) + 1 ; // Calculate the difference between the minimum and maximum elements, plus 1
        result *= mins ; // Multiply the result by the number of occurrences of the minimum element
        result -= mins * ( mins - 1 ) / 2 ; // Subtract the number of combinations of pairs of minimum elements
        cout << result << endl ; // Print the output
    } else {
        long result = ( max - min ) ; // Calculate the difference between the minimum and maximum elements
        result *= mins ; // Multiply the result by the number of occurrences of the minimum element
        result *= maxs ; // Multiply the result by the number of occurrences of the maximum element
        cout << result << endl ; // Print the output
    }

    return 0 ; // Return 0 to indicate successful execution
}

