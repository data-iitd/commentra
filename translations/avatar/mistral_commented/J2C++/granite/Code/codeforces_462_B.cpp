

#include <bits/stdc++.h>  // Including required C++ libraries for input and output

using namespace std ;  // Using the standard namespace

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;  // Disabling synchronization between C and C++ streams
    cin.tie ( NULL ) ;  // Setting the input stream to null to optimize performance
    cout.tie ( NULL ) ;  // Setting the output stream to null to optimize performance

    int n, k ;  // Declaring variables to store the number of cards and queries
    cin >> n >> k ;  // Reading the number of cards and queries from the input

    vector <int> cards ( 26, 0 ) ;  // Creating a vector of size 26 to store the cards
    string s ;  // Declaring a string variable to store the sequence of cards
    cin >> s ;  // Reading the sequence of cards from the input

    for ( int t = 0 ; t < n ; t ++ ) {  // Iterating through each character in the sequence
        cards [ s [ t ] - 'A' ] ++ ;  // Incrementing the left counter of the corresponding card
    }

    long long ans = 0 ;  // Declaring a variable to store the answer
    for ( int i = 0 ; i < k ; i ++ ) {  // Iterating through each query
        sort ( cards.rbegin ( ), cards.rend ( ) ) ;  // Sorting the cards vector in descending order of their left counters
        int change = min ( cards [ 0 ], k - i ) ;  // Calculating the number of cards to be moved
        ans += ( long long ) change * change ;  // Adding the square of the number of cards moved to the answer
        cards [ 0 ] -= change ;  // Decreasing the left counter of the highest card by the number of cards moved
        i += change - 1 ;  // Skipping the next i-1 cards as they will have the same left counter
    }

    cout << ans << endl ;  // Writing the answer to the output stream

    return 0 ;  // Returning 0 to indicate successful execution of the program
}

