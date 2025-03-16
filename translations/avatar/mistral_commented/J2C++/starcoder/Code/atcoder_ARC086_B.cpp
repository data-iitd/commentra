
#include <bits/stdc++.h> // Importing the standard library

using namespace std ; // Using the standard namespace

int main ( ) { // Starting point of the program
    int n ; // Declaring the variable n
    cin >> n ; // Reading the first integer from the standard input stream and assigning it to the variable n
    int a [ n ] ; // Creating an integer array of size n
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
        cin >> a [ i ] ; // Reading the integers from the standard input stream and assigning them to the array a
    }
    int m = 0 ; // Initializing the variable m to 0
    for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
        if ( abs ( a [ m ] ) > abs ( a [ i ] ) ) { // Comparing the absolute values of the first and current elements to find the index of the smallest absolute value
            m = i ; // Assigning the index of the smallest absolute value to the variable m
        }
    }
    vector < string > r ; // Creating an empty vector of Strings to store the output
    if ( a [ m ] >= 0 ) { // Checking if the smallest absolute value is positive
        for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
            r.push_back ( to_string ( m + 1 ) + " " + to_string ( i + 1 ) ) ; // Adding the pair (m+1, i+1) to the vector r if the smallest absolute value is positive
        }
    } else { // If the smallest absolute value is negative
        for ( int i = n ; i > 1 ; -- i ) { // Starting a for loop to iterate through the array a from the last element to the second one
            r.push_back ( to_string ( i + 1 ) + " " + to_string ( i - 1 ) ) ; // Adding the pair (i+1, i-1) to the vector r if the smallest absolute value is negative
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
        if ( a [ m ] >= 0 ^ a [ i ] >= 0 ) { // Checking if the signs of the elements at indices m and i are different
            r.push_back ( to_string ( m + 1 ) + " " + to_string ( i + 1 ) ) ; // Adding the pair (m+1, i+1) to the vector r if the condition is true
        }
    }
    cout << r.size ( ) << endl ; // Printing the size of the vector r to the standard output stream
    for ( string s : r ) { // Starting a for loop to iterate through the vector r
        cout << s << endl ; // Printing each pair in the vector r to the standard output stream
    }

}

