
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    string s, t ;  // Taking two input strings
    cin >> s >> t ;

    map < char, int > freqs ;  // Dictionary to store frequency of characters in s
    map < char, int > freqt ;  // Dictionary to store frequency of characters in t
    int yay = 0, whoops = 0 ;  // Initializing counters for yay and whoops

    // Populating the frequency dictionaries
    for ( char letra : s ) {
        if ( freqs.find ( letra )!= freqs.end ( ) ) {
            freqs [ letra ] += 1 ;  // Incrementing the count if character is already in dictionary
        } else {
            freqs [ letra ] = 1 ;  // Initializing the count if character is not in dictionary
        }
    }

    for ( char letra : t ) {
        if ( freqt.find ( letra )!= freqt.end ( ) ) {
            freqt [ letra ] += 1 ;  // Incrementing the count if character is already in dictionary
        } else {
            freqt [ letra ] = 1 ;  // Initializing the count if character is not in dictionary
        }
    }

    // Counting yay by matching characters in freqs and freqt
    for ( char letra : freqs.keys ( ) ) {
        while ( freqs [ letra ] > 0 && freqt.find ( letra )!= freqt.end ( ) && freqt [ letra ] > 0 ) {
            yay += 1 ;  // Incrementing yay if characters match
            freqs [ letra ] -= 1 ;  // Decrementing the count in freqs
            freqt [ letra ] -= 1 ;  // Decrementing the count in freqt
        }
    }

    // Counting whoops by transforming characters to match
    for ( char letra : freqs.keys ( ) ) {
        while ( freqs [ letra ] > 0 ) {
            if ( islower ( letra ) && freqt.find ( toupper ( letra ) )!= freqt.end ( ) && freqt [ toupper ( letra ) ] > 0 ) {
                whoops += 1 ;  // Incrementing whoops if transformation is possible
                freqs [ letra ] -= 1 ;  // Decrementing the count in freqs
                freqt [ toupper ( letra ) ] -= 1 ;  // Decrementing the count in freqt
            } else if ( isupper ( letra ) && freqt.find ( tolower ( letra ) )!= freqt.end ( ) && freqt [ tolower ( letra ) ] > 0 ) {
                whoops += 1 ;  // Incrementing whoops if transformation is possible
                freqs [ letra ] -= 1 ;  // Decrementing the count in freqs
                freqt [ tolower ( letra ) ] -= 1 ;  // Decrementing the count in freqt
            } else {
                break ;  // Breaking the loop if no more transformations are possible
            }
        }
    }

    cout << yay << " " << whoops << endl ;  // Printing the final counts of yay and whoops

    return 0 ;
}
