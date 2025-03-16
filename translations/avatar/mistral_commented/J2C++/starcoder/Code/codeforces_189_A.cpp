
#include <bits/stdc++.h> // Importing the standard library

using namespace std ; // Using the standard library

int main ( ) { // Starting the main method
    int n ; // Defining the number of elements in the array
    cin >> n ; // Reading the number of elements in the array from the console

    int maxn = 4010 ; // Defining the maximum size of the dynamic programming array

    // Reading the three integers representing the array elements
    int a, b, c ;
    cin >> a >> b >> c ;

    // Defining an array to store the array elements
    int arr [ 3 ] = { a, b, c } ;

    int dp [ maxn ] ; // Creating a dynamic programming array of size maxn

    // Initializing the dynamic programming array with minimum values
    for ( int i = 0 ; i < n ; i ++ ) {
        dp [ i ] = INT_MIN ; // Setting all elements to minimum value
    }

    dp [ 0 ] = 0 ; // Setting the first element to 0

    // Filling the dynamic programming array using two nested loops
    for ( int i = 0 ; i < 3 ; i ++ ) { // Looping through the array elements
        for ( int j = arr [ i ] ; j < maxn ; j ++ ) { // Looping through the dynamic programming array
            dp [ j ] = max ( dp [ j ], dp [ j - arr [ i ] ] + 1 ) ; // Updating the maximum length ending at j
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    cout << dp [ n ] ;
}

