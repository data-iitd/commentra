
#include <iostream>
#include <cmath>

using namespace std ;

int main ( ) {
    int n ; // Step 6: Read the number of beacons
    int max = 0 ; // Step 5: Initialize the maximum value in dp array
    int beacon [ 1000001 ] ; // Step 5: Initialize the beacon array
    int dp [ 1000001 ] ; // Step 5: Initialize the dp array

    // Step 6: Read the positions and strengths of the beacons
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int a ;
        cin >> a ;
        beacon [ a ] = a ;
    }

    // Step 7: Check if the first beacon's strength is not zero and initialize dp[0] to 1
    if ( beacon [ 0 ] != 0 ) dp [ 0 ] = 1 ;

    // Step 8: Iterate through the range of 1 to 1000000, updating the dp array based on the beacon strengths
    for ( int i = 1 ; i < 1000001 ; i ++ ) {
        if ( beacon [ i ] != 0 && beacon [ i ] < i ) {
            dp [ i ] = dp [ i - beacon [ i ] - 1 ] + 1 ;
        } else if ( beacon [ i ] != 0 ) {
            dp [ i ] = 1 ;
        } else {
            dp [ i ] = dp [ i - 1 ] ;
        }
        max = max ( max , dp [ i ] ) ; // Step 9: Update the maximum value in dp array
    }

    // Step 9: Print the result
    cout << n - max << endl ;

    return 0 ;
}

