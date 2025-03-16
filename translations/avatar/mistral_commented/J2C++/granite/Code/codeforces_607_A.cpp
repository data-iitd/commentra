

#include <bits/stdc++.h>  // Include necessary libraries for input and output

using namespace std ;  // Using the standard namespace

int main ( ) {  // Main method starts the execution of C++ program
    ios_base::sync_with_stdio ( false ) ;  // Disabling synchronization between C and C++ streams
    cin.tie ( NULL ) ;  // Setting the input stream to null
    cout.tie ( NULL ) ;  // Setting the output stream to null

    int max = 0 ;  // Initializing max variable to store the maximum length of a subsequence
    int n ;  // Declaring n variable to store the number of elements in the array
    cin >> n ;  // Reading the number of elements in the array from the console

    vector < int > beacon ( 1000001, 0 ) ;  // Creating a vector of size 1000001 to store the indices of beacons
    vector < int > dp ( 1000001, 0 ) ;  // Creating a vector of size 1000001 to store the length of the longest subsequence ending at each index

    for ( int i = 0 ; i < n ; i ++ ) {  // Loop to read the elements and their indices from the console
        int a, b ;  // Declaring a and b variables to store the element and its index
        cin >> a >> b ;  // Reading the element and its index from the console
        beacon [ a ] = b ;  // Storing the index of the beacon for the given element
    }

    if ( beacon [ 0 ]!= 0 ) dp [ 0 ] = 1 ;  // If the first beacon exists, the length of the subsequence ending at index 0 is 1

    for ( int i = 1 ; i < 1000001 ; i ++ ) {  // Loop to calculate the length of the longest subsequence ending at each index
        if ( beacon [ i ]!= 0 && beacon [ i ] < i ) {
            dp [ i ] = dp [ i - beacon [ i ] - 1 ] + 1 ;  // If the beacon exists and its index is less than the current index, update the length of the subsequence
        } else if ( beacon [ i ]!= 0 ) {
            dp [ i ] = 1 ;  // If the beacon exists but its index is greater than or equal to the current index, the length of the subsequence is 1
        } else {
            dp [ i ] = dp [ i - 1 ] ;  // If there is no beacon, the length of the subsequence remains the same as the previous index
        }
        max = max ( max, dp [ i ] ) ;  // Updating the maximum length of the subsequence
    }

    cout << n - max ;  // Printing the difference between the total number of elements and the maximum length of the subsequence

    return 0 ;  // Returning 0 to indicate successful execution of the program
}

These comments should provide a clear understanding of the logic behind each part of the code.