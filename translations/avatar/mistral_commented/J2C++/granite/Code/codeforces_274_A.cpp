

#include <bits/stdc++.h> // Include the standard library header file

using namespace std ; // Using the standard namespace

int main ( ) { // Defining the main function
    ios_base::sync_with_stdio ( false ) ; // Disabling synchronization between C and C++ streams
    cin.tie ( NULL ) ; // Setting the input stream to null

    int n ; // Declaring an integer variable n to store the length of the array
    long long k ; // Declaring a long long integer variable k to store the divisor value

    cin >> n >> k ; // Reading the values of n and k from the standard input stream

    vector < long long > arr ( n ) ; // Creating a vector named arr of length n to store long long integer values
    unordered_set < long long > set ; // Creating an unordered_set named set to store unique long long integer values

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the vector arr from index 0 to n-1
        cin >> arr [ i ] ; // Reading a long long integer value from the standard input stream and storing it in the arr[i] index
    }

    sort ( arr.begin ( ), arr.end ( ) ) ; // Sorting the arr vector in ascending order using the sort() function

    int count = 0 ; // Initializing the count variable to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the sorted arr vector from index 0 to n-1
        if ( arr [ i ] % k!= 0 ) { // Checking if the arr[i] value is not divisible by k
            count ++ ; // Incrementing the count variable if the condition is true
            set.insert ( arr [ i ] ) ; // Inserting the arr[i] value into the set if it is not already present
        } else if ( set.find ( arr [ i ] / k ) == set.end ( ) ) { // Checking if the arr[i] value is divisible by k and if its quotient is not present in the set
            count ++ ; // Incrementing the count variable if the condition is true
            set.insert ( arr [ i ] ) ; // Inserting the arr[i] value into the set if it is not already present
        }
    }

    cout << count << endl ; // Printing the count value to the standard output stream

    return 0 ; // Returning 0 to indicate successful program execution
}

These comments should provide a clear understanding of the code's functionality and logic.