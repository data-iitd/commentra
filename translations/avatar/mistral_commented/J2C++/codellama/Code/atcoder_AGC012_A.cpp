
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std ;

int main ( ) {
    int n ;  // Number of elements in the array
    cin >> n ;  // Reading the number of elements in the array from the standard input
    int array [ 3 * n ] ;  // Creating an integer array of size 3 times the number of elements

    // Initializing the array with input values
    for ( int i = 0 ; i < 3 * n ; i ++ )
        cin >> array [ i ] ;

    // Sorting the array in ascending order
    sort ( array , array + 3 * n ) ;

    int head = 3 * n - 2 ;  // Index of the last element to be considered in the current iteration
    long res = 0 ;  // Result variable to store the sum of the last two elements in each subarray

    // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for ( int i = 0 ; i < n ; i ++ ) {
        res += array [ head ] ;  // Adding the last element of the current subarray to the result
        head -= 2 ;  // Decreasing the index of the last element by 2 to consider the next subarray
    }

    // Printing the result
    cout << res << endl ;

    return 0 ;
}

