
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main ( ) {
    int x [ 3 ] ; // Declaring and initializing an integer array x of size 3
    int max = 0 ; // Initializing max to 0

    // Reading the size of the array x from the standard input stream
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> x [ i ] ; // Reading the i-th element of the array x from the standard input stream
        max = max < x [ i ] ? x [ i ] : max ; // Finding the maximum element of the array x
    }

    int k ; // Declaring and initializing an integer k
    cin >> k ; // Reading the integer k from the standard input stream

    vector < long long > a [ 3 ] ; // Declaring and initializing an array a of size 3, where each element is a vector of long longs

    // Reading the elements of each sub-vector a[i] of size x[i] from the standard input stream and sorting it in ascending order
    for ( int i = 0 ; i < 3 ; ++ i ) {
        a [ i ] = vector < long long > ( x [ i ] ) ;
        for ( int j = 0 ; j < x [ i ] ; ++ j ) {
            cin >> a [ i ] [ j ] ; // Reading the j-th element of the sub-vector a[i] from the standard input stream
        }
        sort ( a [ i ].begin ( ) , a [ i ].end ( ) ) ; // Sorting the sub-vector a[i] in ascending order
    }

    vector < long long > ans ; // Declaring and initializing an empty vector ans to store the sum of three elements from different sub-vectors that are less than or equal to k

    // Finding all such sums and adding them to the vector ans
    for ( int i = 0 ; i < x [ 0 ] ; ++ i ) {
        for ( int j = 0 ; j < x [ 1 ] ; ++ j ) {
            for ( int m = 0 ; m < x [ 2 ] ; ++ m ) {
                if ( ( i + 1 ) * ( j + 1 ) * ( m + 1 ) <= k ) { // Checking if the product of (i+1), (j+1), and (m+1) is less than or equal to k
                    long long tmp = a [ 0 ] [ x [ 0 ] - i - 1 ] // Getting the (x[0]-i)-th element of the sub-vector a[0]
                            + a [ 1 ] [ x [ 1 ] - j - 1 ] // Getting the (x[1]-j)-th element of the sub-vector a[1]
                            + a [ 2 ] [ x [ 2 ] - m - 1 ] ; // Getting the (x[2]-m)-th element of the sub-vector a[2]
                    ans.push_back ( tmp ) ; // Adding the sum of the three elements to the vector ans
                }
            }
        }
    }

    sort ( ans.begin ( ) , ans.end ( ) ) ; // Sorting the vector ans in ascending order

    int n = ans.size ( ) ; // Getting the size of the vector ans

    // Printing the i-th element of the vector ans, where i is the index of the element to be printed, starting from the last one
    for ( int i = 0 ; i < k ; ++ i ) {
        cout << ans [ n - i - 1 ] << endl ;
    }

    return 0 ;
}

