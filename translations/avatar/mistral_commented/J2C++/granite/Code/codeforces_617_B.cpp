
#include <bits/stdc++.h>  // Include the C++ Standard Template Library (STL)

using namespace std ;  // Using the STL namespace

int main ( ) {   // Defining the main function
    int n ;  // Declare an integer variable n to store the size of the array

    cin >> n ;  // Read the first integer from the input as the size of the array

    vector < int > arr ;  // Create an empty vector to store the indices of the 1's in the input

    for ( int i = 0 ; i < n ; i ++ ) {   // Loop through the input to find the indices of the 1's
        int x ;  // Declare an integer variable x to store the current input

        cin >> x ;  // Read the current input from the input

        if ( x == 1 )
            arr.push_back ( i ) ;  // If the current input is 1, add its index to the vector
    }

    if ( arr.empty ( ) ) {   // Check if the vector is empty
        cout << 0 << endl ;  // If it is, print 0 as the output
    } else {
        long long result = 1 ;  // Initialize the result variable to 1

        for ( int i = 1 ; i < arr.size ( ) ; i ++ ) {  // Loop through the vector to calculate the result
            result *= arr [ i ] - arr [ i - 1 ] ;  // Multiply the difference between two consecutive indices to the result
        }

        cout << result << endl ;  // Print the result as the output
    }

    return 0 ;  // Return 0 to indicate successful execution of the program
}
