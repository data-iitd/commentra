

#include <bits/stdc++.h> // Including the standard library for C++

using namespace std ; // Using the standard namespace for C++

int main ( ) { // Starting point of the program, main method with an empty argument list
    ios_base::sync_with_stdio ( false ) ; // Disabling synchronization between C and C++ standard input and output streams
    cin.tie ( NULL ) ; // Disabling buffering for the C++ standard input stream
    int n ; // Declaring an integer variable n to store the size of the array
    cin >> n ; // Reading the first integer from the standard input stream and assigning it to the variable n
    vector < int > a ( n ) ; // Creating a vector of integers of size n to store the input array
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the vector a from the first element to the last one
        cin >> a [ i ] ; // Reading an integer from the standard input stream and assigning it to the ith element of the vector a
    }
    vector < pair < int, int > > r ; // Creating a vector of pairs of integers to store the output
    int m = 0 ; // Initializing the variable m to 0
    for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the vector a from the second element to the last one
        if ( abs ( a [ m ] ) > abs ( a [ i ] ) ) { // Comparing the absolute values of the first and current elements to find the index of the smallest absolute value
            m = i ; // Assigning the index of the smallest absolute value to the variable m
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the vector a from the first element to the last one
        if ( a [ m ] >= 0 ^ a [ i ] >= 0 ) { // Checking if the signs of the elements at indices m and i are different
            r.push_back ( make_pair ( i + 1, m + 1 ) ) ; // Adding the pair (i+1, m+1) to the vector r if the condition is true
        }
    }
    if ( a [ m ] >= 0 ) { // Checking if the smallest absolute value is positive
        for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the vector a from the second element to the last one
            r.push_back ( make_pair ( i, i + 1 ) ) ; // Adding the pair (i, i+1) to the vector r if the smallest absolute value is positive
        }
    } else { // If the smallest absolute value is negative
        for ( int i = n ; i > 1 ; -- i ) { // Starting a for loop to iterate through the vector a from the last element to the second one
            r.push_back ( make_pair ( i, i - 1 ) ) ; // Adding the pair (i, i-1) to the vector r if the smallest absolute value is negative
        }
    }
    cout << r.size ( ) << endl ; // Printing the size of the vector r to the standard output stream
    for ( auto p : r ) { // Starting a for loop to iterate through the vector r
        cout << p.first << " " << p.second << endl ; // Printing each pair in the vector r to the standard output stream
    }
    return 0 ; // Returning 0 to indicate successful execution of the program
}

