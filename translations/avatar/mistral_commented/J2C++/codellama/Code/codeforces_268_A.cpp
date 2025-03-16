
#include <iostream>
#include <cstdlib>

using namespace std ; // Using the standard namespace std

int main ( ) { // Defining the main function
    int n ; // Declaring the variable n
    cin >> n ; // Reading the first line of the input containing the number of integers n

    int result = 0 ; // Initializing the variable result to zero

    int h [ n ] ; // Creating an integer array h of size n
    int g [ n ] ; // Creating an integer array g of size n

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each index i from 0 to n-1 in the first for loop
        cin >> h [ i ] ; // Reading an integer value from the standard input stream and assigning it to the current index of array h
        cin >> g [ i ] ; // Reading an integer value from the standard input stream and assigning it to the current index of array g
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each index i from 0 to n-1 in the second for loop
        for ( int j = 0 ; j < n ; j ++ ) { // Nested for loop iterating through each index j from 0 to n-1
            if ( h [ i ] == g [ j ] ) { // Checking if the current element of array h is equal to the current element of array g
                result ++ ; // Incrementing the result variable if the condition is true
            }
        }
    }

    cout << result << endl ; // Printing the final result to the standard output stream

    return 0 ; // Returning zero to indicate that the program executed successfully
}

