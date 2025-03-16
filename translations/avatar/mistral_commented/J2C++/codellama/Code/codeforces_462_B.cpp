
#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

struct c462b {  // Defining a structure to represent a card
    int left = 0 ;  // The left counter of the card

    bool operator < ( const c462b & o ) const {  // Overriding the less than operator for custom comparison
        return left < o.left ;
    }
} ;

int main ( ) {
    int n, k ;  // Reading the number of cards and the number of queries
    cin >> n >> k ;

    string s ;  // Reading the sequence of cards
    cin >> s ;

    c462b cards [ 26 ] ;  // Creating an array of size 26 to store the cards
    for ( int i = 0 ; i < 26 ; i ++ ) {  // Initializing the cards array with default values
        cards [ i ].left = 0 ;
    }

    for ( int t = 0 ; t < n ; t ++ ) {  // Iterating through each character in the sequence
        cards [ s [ t ] - 'A' ].left ++ ;  // Incrementing the left counter of the corresponding card
    }

    long ans = 0 ;  // Initializing the answer variable to zero
    for ( int i = 0 ; i < k ; i ++ ) {  // Iterating through each query
        sort ( cards, cards + 26 ) ;  // Sorting the cards array in descending order of their left counters
        long change = min ( cards [ 25 ].left, k - i ) ;  // Calculating the number of cards to be moved
        ans += change * change ;  // Adding the square of the number of cards moved to the answer
        cards [ 25 ].left -= change ;  // Decreasing the left counter of the highest card by the number of cards moved
        i += change - 1 ;  // Skipping the next i-1 cards as they will have the same left counter
    }

    cout << ans << endl ;  // Writing the answer to the standard output

    return 0 ;
}

