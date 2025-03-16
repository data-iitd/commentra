

#include <bits/stdc++.h> // Include the necessary libraries

using namespace std ; // Using the namespace std

int main ( ) { // Main function to start the program
    int N, M ; // Declaring variables to store the size of the ArrayList and the number of queries
    cin >> N >> M ; // Reading the size of the ArrayList and the number of queries from the input

    vector < int > a ( N ) ; // Creating a vector of size N to store integers

    // Initializing the vector with zeros
    for ( int i = 0 ; i < N ; i ++ ) {
        a [ i ] = 0 ;
    }

    // Reading the queries and updating the vector accordingly
    for ( int i = 0 ; i < M ; i ++ ) {
        int k ; // Declaring a variable to store the number of elements to be updated
        cin >> k ; // Reading the number of elements to be updated

        for ( int j = 0 ; j < k ; j ++ ) { // Iterating through the elements to be updated
            int s ; // Declaring a variable to store the index of the element to be updated
            cin >> s ; // Reading the index of the element to be updated
            s -- ; // Decreasing the index by 1 as the vector index starts from 0

            // Updating the value of the element at the given index
            a [ s ] |= ( 1 << i ) ;
        }
    }

    int p = 0 ; // Declaring a variable to store the XOR of all given integers

    // Reading the integers and computing their XOR
    for ( int i = 0 ; i < M ; i ++ ) {
        int x ; // Declaring a variable to store an integer from the input
        cin >> x ; // Reading an integer from the input
        p |= ( x << i ) ; // Computing the XOR of the current integer with the previous result
    }

    int ans = 0 ; // Declaring a variable to store the count of valid answers

    // Iterating through all possible combinations of the vector elements
    for ( int s = 0 ; s < ( 1 << N ) ; s ++ ) { // 1 << N represents 2^N
        int t = 0 ; // Declaring a variable to store the XOR of the current combination with the vector elements

        // Computing the XOR of the current combination with the vector elements
        for ( int i = 0 ; i < N ; i ++ ) {
            if ( ( ( s >> i ) & 1 ) == 1 ) { // Checking if the i-th bit of the current combination is set
                t ^= a [ i ] ; // Updating the XOR of the current combination
            }
        }

        // Checking if the XOR of the current combination and the vector elements is equal to the given integers
        if ( p == t ) {
            ans ++ ; // Incrementing the count of valid answers
        }
    }

    cout << ans << endl ; // Printing the count of valid answers

    return 0 ; // Returning 0 to indicate successful execution of the program
}

