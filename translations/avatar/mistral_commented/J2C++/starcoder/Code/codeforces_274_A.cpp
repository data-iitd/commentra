
#include <bits/stdc++.h> // Importing the standard library

using namespace std ; // Using the standard namespace

int main ( ) { // Defining the main function that is executed when the program runs
    int n ; // Declaring the n variable
    long long k ; // Declaring the k variable
    cin >> n >> k ; // Reading the first integer value n and the long integer value k from the standard input stream

    long long arr [ n ] ; // Declaring an array named arr of length n to store long integer values
    unordered_set < long long > set ; // Declaring an empty unordered_set named set to store unique long integer values

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the array arr from index 0 to n-1
        cin >> arr [ i ] ; // Reading a long integer value from the standard input stream and storing it in the arr[i] index
    }

    sort ( arr, arr + n ) ; // Sorting the arr array in ascending order using the sort() function

    int count = 0 ; // Initializing the count variable to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the sorted arr array from index 0 to n-1
        if ( arr [ i ] % k!= 0 ) { // Checking if the arr[i] value is not divisible by k
            count ++ ; // Incrementing the count variable if the condition is true
            set.insert ( arr [ i ] ) ; // Adding the arr[i] value to the set if it is not already present
        } else if ( set.find ( arr [ i ] / k ) == set.end ( ) ) { // Checking if the arr[i] value is divisible by k and if its quotient is not present in the set
            count ++ ; // Incrementing the count variable if the condition is true
            set.insert ( arr [ i ] ) ; // Adding the arr[i] value to the set if it is not already present
        }
    }

    cout << count << endl ; // Printing the count value to the standard output stream
}

