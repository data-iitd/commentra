#include <bits/stdc++.h>
using namespace std;

// Final static constant for the maximum size of the array
const int NUM = ( int ) ( 1e5 + 2 ) ;

int main ( ) {
    // Creating a Scanner object to read input
    cin.sync_with_stdio ( false ) ;
    cin.tie ( 0 ) ;
    cin.exceptions ( ios :: failbit ) ;
    int N ;
    cin >> N ;

    // Creating an empty HashMap to store the index of each unique element
    unordered_map < int, int > map ;

    // Creating an empty PriorityQueue to store the elements in ascending order
    priority_queue < int > nums ;

    // Reading the elements one by one and adding them to the PriorityQueue and HashMap
    for ( int i = 0 ; i < N ; i ++ ) {
        int tmp ;
        cin >> tmp ;
        nums.push ( tmp ) ;
        map [ tmp ] = i ;
    }

    int bin = 0 ; // Initializing a binary index variable
    int diff = 0 ; // Initializing a variable to store the difference in parity between elements

    // Processing the elements in the PriorityQueue
    while (! nums.empty ( ) ) {
        int num = nums.top ( ) ; // Polling an element from the PriorityQueue
        int idx = map [ num ] ; // Getting the index of the element from the HashMap

        // Checking if the binary index and the index of the current element have opposite parity
        if ( ( bin % 2 )!= ( idx % 2 ) ) {
            diff ++ ; // Incrementing the difference if the condition is true
        }

        bin ++ ; // Incrementing the binary index
        bin %= 2 ; // Setting the binary index to 0 or 1 based on the current parity
    }

    // Calculating and printing the answer
    int ans = ( diff / 2 ) ;
    cout << ans << endl ;
}

