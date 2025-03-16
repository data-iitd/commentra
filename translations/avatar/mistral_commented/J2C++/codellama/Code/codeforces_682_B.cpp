
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main ( ) {
    // Creating a vector to store the elements
    vector < int > list ;

    // Reading the number of elements from the input
    int n ;
    cin >> n ;

    // Reading 'n' elements from the input and adding them to the vector
    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;
        list.push_back ( x ) ;
    }

    // Sorting the vector in ascending order using sort() method
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

    // Closing the input and output streams
    cin.close ( ) ;
    cout.close ( ) ;

    // Debugging method to print the deep toString representation of an object
    static void debug ( const vector < int > &list ) {
        for ( int i = 0 ; i < list.size ( ) ; i ++ ) {
            cout << list [ i ] << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}

