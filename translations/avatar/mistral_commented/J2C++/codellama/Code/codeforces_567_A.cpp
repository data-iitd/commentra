
#include <iostream>
#include <cmath>

using namespace std ;

int main ( ) {
    int a ; // Declaring variable for storing size of the array
    int ar [ ] ; // Declaring array for storing elements
    int max , min ; // Declaring variables for storing maximum and minimum differences

    // Asking user for the size of the array and initializing it
    cout << "Enter the size of the array: " ;
    cin >> a ;
    ar = new int [ a ] ;

    // Initializing variables for storing maximum and minimum differences
    max = 0 ;
    min = 0 ;

    // Reading array elements from user input
    for ( int i = 0 ; i < a ; i ++ ) {
        cout << "Enter element " << i + 1 << ": " ;
        cin >> ar [ i ] ;
    }

    // Finding maximum and minimum differences between consecutive elements in the array
    for ( int i = 0 ; i < a ; i ++ ) {
        // Finding maximum difference between current element and first element
        max = max ( ar [ i ] - ar [ 0 ] , ar [ a - 1 ] - ar [ i ] ) ;

        // Finding minimum difference between current element and previous element
        if ( i == 0 ) {
            min = ar [ i + 1 ] - ar [ i ] ; // For the first element, minimum difference is between current and next element
        } else if ( i == a - 1 ) {
            min = ar [ i ] - ar [ i - 1 ] ; // For the last element, minimum difference is between current and previous element
        } else {
            min = min ( ar [ i ] - ar [ i - 1 ] , ar [ i + 1 ] - ar [ i ] ) ; // For other elements, minimum difference is between current and previous or next element, whichever is smaller
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        cout << min << " " << max << endl ;
    }

    return 0 ;
}

