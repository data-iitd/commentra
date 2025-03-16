

#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int x, y, z, k ;
    cin >> x >> y >> z >> k ;
    // Taking four integer inputs: x, y, z, and k

    vector < int > a ( x ) ;
    // Initializing a vector a of size x to store integers

    for ( int i = 0 ; i < x ; i ++ ) {
        cin >> a [ i ] ;
        // Reading x integers and storing them in vector a
    }

    vector < int > b ( y ) ;
    // Initializing a vector b of size y to store integers

    for ( int i = 0 ; i < y ; i ++ ) {
        cin >> b [ i ] ;
        // Reading y integers and storing them in vector b
    }

    vector < int > c ( z ) ;
    // Initializing a vector c of size z to store integers

    for ( int i = 0 ; i < z ; i ++ ) {
        cin >> c [ i ] ;
        // Reading z integers and storing them in vector c
    }

    vector < int > ab ;
    // Initializing an empty vector ab to store sums of elements from a and b

    for ( int i = 0 ; i < x ; i ++ ) {
        for ( int j = 0 ; j < y ; j ++ ) {
            ab.push_back ( a [ i ] + b [ j ] ) ;
            // Adding the sum of elements from a and b to vector ab
        }
    }

    sort ( ab.rbegin ( ), ab.rend ( ) ) ;
    // Sorting vector ab in descending order

    vector < int > abc ;
    // Initializing an empty vector abc to store sums of elements from ab and c

    for ( int i = 0 ; i < min ( k, x * y ) ; i ++ ) {
        for ( int j = 0 ; j < z ; j ++ ) {
            abc.push_back ( ab [ i ] + c [ j ] ) ;
            // Adding the sum of elements from ab and c to vector abc
        }
    }

    sort ( abc.rbegin ( ), abc.rend ( ) ) ;
    // Sorting vector abc in descending order

    for ( int i = 0 ; i < k ; i ++ ) {
        cout << abc [ i ] << endl ;
        // Printing the first k elements of abc in descending order
    }

    return 0 ;
    // Returning 0 to indicate successful execution
}
