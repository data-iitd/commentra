
#include <bits/stdc++.h>
using namespace std;

// Final static constant for the maximum size of the array
const int NUM = ( int ) ( 1e5 + 2 ) ;

int main ( ) {
    ios_base::sync_with_stdio ( false ) ; // Disabling synchronization between C and C++ streams
    cin.tie ( NULL ) ; // Setting the input stream to null

    int N ; // Declaring a variable to store the number of elements in the array
    cin >> N ; // Reading the number of elements in the array

    // Creating an empty unordered_map to store the index of each unique element
    unordered_map < int, int > map ;

    // Creating an empty priority_queue to store the elements in ascending order
    priority_queue < int > nums ;

    // Reading the elements one by one and adding them to the priority_queue and unordered_map
    for ( int i = 0 ; i < N ; i ++ ) {
        int tmp ; // Declaring a variable to store the current element
        cin >> tmp ; // Reading an element
        nums.push ( tmp ) ; // Adding the element to the priority_queue
        map [ tmp ] = i ; // Adding the index of the element to the unordered_map
    }

    int bin = 0 ; // Initializing a binary index variable
    int diff = 0 ; // Initializing a variable to store the difference in parity between elements

    // Processing the elements in the priority_queue
    while (! nums.empty ( ) ) {
        int num = nums.top ( ) ; // Getting the top element from the priority_queue
        nums.pop ( ) ; // Removing the top element from the priority_queue
        int idx = map [ num ] ; // Getting the index of the element from the unordered_map

        // Checking if the binary index and the index of the current element have opposite parity
        if ( ( bin % 2 )!= ( idx % 2 ) ) {
            diff ++ ; // Incrementing the difference if the condition is true
        }

        bin ++ ; // Incrementing the binary index
        bin %= 2 ; // Setting the binary index to 0 or 1 based on the current parity
    }

    // Calculating and printing the answer
    int ans = ( diff / 2 ) ;
    cout << ans << endl ; // Printing the answer

    return 0 ; // Returning 0 to indicate successful execution
}

