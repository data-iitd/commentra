
#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    int N ;
    cin >> N ;
    int A [ N ] ;
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> A [ i ] ;
        // Comment: Reading the i-th element of the array from the standard input
    }

    int count = 0 ;
    for ( int i = 0 ; i < N - 1 ; i ++ ) {
        if ( i == N - 1 ) count ++ ;
        else if ( A [ i ] == A [ i + 1 ] ) ;
        else if ( A [ i ] < A [ i + 1 ] ) {
            while ( A [ i ] <= A [ i + 1 ] ) {
                i ++ ;
                if ( i == N - 1 ) break ;
            }
            count ++ ;
        } else {
            while ( A [ i ] >= A [ i + 1 ] ) {
                i ++ ;
                if ( i == N - 1 ) break ;
            }
            count ++ ;
        }
    }

    cout << count << endl ;
    // Comment: Printing the final count
}

