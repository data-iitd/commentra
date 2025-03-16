
#include <bits/stdc++.h> // Include the necessary header files

using namespace std ; // Use the standard namespace

int main ( ) { // Define the main function
    ios_base::sync_with_stdio ( false ) ; // Disable synchronization between C and C++ streams
    cin.tie ( NULL ) ; // Disable the use of C-style input functions in C++

    int n, b ; // Declare the variables n and b
    cin >> n >> b ; // Read the values of n and b from the standard input

    vector < long long > ans ( n ) ; // Create a vector of long long type named ans with a length equal to the value of n
    queue < long long > q ; // Create an empty queue of long long type named q

    for ( int i = 0 ; i < n ; i ++ ) { // Start a for loop that iterates from 0 to n-1
        int t, d ; // Declare the variables t and d
        cin >> t >> d ; // Read the values of t and d from the standard input

        while (! q.empty ( ) && q.front ( ) <= t ) { // Use a while loop to remove the smallest element from the queue if it is less than or equal to t
            q.pop ( ) ; // Remove the smallest element from the queue
        }

        if ( q.size ( ) <= b ) { // Check whether the size of the queue is less than or equal to b
            ans [ i ] = ( q.empty ( )? t : q.back ( ) ) + d ; // Calculate the answer for the current test case and add it to the queue
            q.push ( ans [ i ] ) ; // Add the answer to the queue
        } else {
            ans [ i ] = - 1 ; // If the condition is false, set the answer for the current test case to -1
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Start a for loop that iterates from 0 to n-1
        cout << ans [ i ] << " " ; // Print the answer for the current test case followed by a space
    }

    cout << endl ; // Print a new line

    return 0 ; // Return 0 to indicate successful execution of the program
}

