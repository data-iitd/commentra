
#include <bits/stdc++.h>
using namespace std ;

int main ( ) {
    // Creating a scanner object for reading input from the standard input
    cin >> ws ;
    cin.sync ( ) ;
    // Creating a print writer object for writing output to the standard output
    cout << fixed << setprecision ( 1 ) ;
    // Creating a print writer object for writing output to the standard output
    ofstream fout ( "output.txt" ) ;
    // Creating a print writer object for writing output to the standard output
    auto coutbuf = cout.rdbuf ( ), & outbuf = fout.rdbuf ( ) ;
    // Redirecting the standard output to the print writer object
    cout.rdbuf ( outbuf ) ;

    // Reading the number of elements in the list from the input
    int n ;
    cin >> n ;

    // Creating an array list of size 'n' to store the elements
    vector < int > list ( n ) ;

    // Reading 'n' elements from the input and adding them to the array list
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> list [ i ] ;
    }

    // Sorting the array list in ascending order using sort() method
    sort ( list.begin ( ), list.end ( ) ) ;

    // Initializing a variable 'c' to keep track of the number of distinct elements
    int c = 1 ;

    // Iterating through the array list to find the number of distinct elements
    for ( int i = 0 ; i < n ; i ++ ) {
        // If the current element is greater than or equal to the current count 'c', increment the count
        if ( list [ i ] >= c ) {
            c ++ ;
        }
    }

    // Writing the result to the output
    cout << c << endl ;

    // Closing the print writer object
    cout.rdbuf ( coutbuf ) ;
    fout.close ( ) ;

    // Debugging method to print the deep toString representation of an object
    template < typename T > void debug ( T & x ) {
        cerr << "Type: " << typeid ( T ). name ( ) << endl ;
        cerr << "Value: " << x << endl ;
    }
}

