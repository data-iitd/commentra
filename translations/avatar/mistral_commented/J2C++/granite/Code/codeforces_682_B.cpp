

#include <bits/stdc++.h>  // Include necessary libraries for input and output

using namespace std;  // Using the standard namespace

int main ( ) {
    // Creating a stream object for reading input from the standard input
    cin.tie ( 0 ) -> sync_with_stdio ( 0 ) ;

    // Creating a stream object for writing output to the standard output
    ofstream cout ( "output.txt" ) ;

    // Reading the number of elements in the list from the input
    int n ;
    cin >> n ;

    // Creating a vector of size 'n' to store the elements
    vector < int > list ( n ) ;

    // Reading 'n' elements from the input and adding them to the vector
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> list [ i ] ;  // Reading an integer from the input and adding it to the vector
    }

    // Sorting the vector in ascending order using std::sort() function
    sort ( list.begin ( ), list.end ( ) ) ;

    // Initializing a variable 'c' to keep track of the number of distinct elements
    int c = 1 ;

    // Iterating through the vector to find the number of distinct elements
    for ( int i = 0 ; i < n ; i ++ ) {
        // If the current element is greater than or equal to the current count 'c', increment the count
        if ( list [ i ] >= c ) {
            c ++ ;
        }
    }

    // Writing the result to the output
    cout << c << endl ;

    // Debugging method to print the deep toString representation of an object
    static void debug ( Object...obj ) {
        System.err.println ( Arrays.deepToString ( obj ) ) ;
    }

    return 0 ;
}

