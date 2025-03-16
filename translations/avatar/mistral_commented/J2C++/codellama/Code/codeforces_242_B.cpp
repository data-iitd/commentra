
#include <iostream>
#include <vector>
#include <cmath>

using namespace std ;

int main ( ) {
    int n ;
    cin >> n ;  // Reading the number of elements in the arrays

    vector < int > a ( n ) ;  // Creating a vector to store the first array elements
    vector < int > b ( n ) ;  // Creating a vector to store the second array elements

    int left = 1e9 + 5 , right = 0 ;  // Initializing left and right variables to store the minimum and maximum elements respectively

    // Reading the elements of the arrays and updating the minimum and maximum elements
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a [ i ] ;  // Reading an element from the first array and adding it to the vector
        cin >> b [ i ] ;  // Reading an element from the second array and adding it to the vector
        left = min ( left , a [ i ] ) ;  // Finding the minimum element in the first array
        right = max ( right , b [ i ] ) ;  // Finding the maximum element in the second array
    }

    // Checking if there is an element that has the same minimum and maximum value in both arrays
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( left == a [ i ] && right == b [ i ] ) {  // Checking if the current element in both arrays has the same minimum and maximum value
            cout << i + 1 << endl ;  // If true, printing the index of the element
            return 0 ;  // Exiting the program after finding the element
        }
    }

    // If no such element is found, printing -1
    cout << - 1 << endl ;

    return 0 ;
}

