#include <iostream>
#include <string>
#include <unordered_map>
using namespace std ;

int main ( ) {
    string s , t ;  // Taking two input strings
    cin >> s >> t ;
    unordered_map < char , int > freqs , freqt ;  // Dictionary to store frequency of characters in s
    unordered_map < char , int > :: iterator it ;  // Iterator for the dictionaries
    int yay , whoops ;  // Initializing counters for yay and whoops

    // Populating the frequency dictionaries
    for ( int i = 0 ; i < s.length ( ) ; i++ ) {
        if ( freqs.find ( s [ i ] ) != freqs.end ( ) ) {
            freqs [ s [ i ] ] += 1 ;  // Incrementing the count if character is already in dictionary
        }
        else {
            freqs [ s [ i ] ] = 1 ;  // Initializing the count if character is not in dictionary
        }
    }

    for ( int i = 0 ; i < t.length ( ) ; i++ ) {
        if ( freqt.find ( t [ i ] ) != freqt.end ( ) ) {
            freqt [ t [ i ] ] += 1 ;  // Incrementing the count if character is already in dictionary
        }
        else {
            freqt [ t [ i ] ] = 1 ;  // Initializing the count if character is not in dictionary
        }
    }

    // Counting yay by matching characters in freqs and freqt
    for ( it = freqs.begin ( ) ; it != freqs.end ( ) ; it++ ) {
        while ( it -> second > 0 and freqt.find ( it -> first ) != freqt.end ( ) and freqt [ it -> first ] > 0 ) {
            yay += 1 ;  // Incrementing yay if characters match
            it -> second -= 1 ;  // Decrementing the count in freqs
            freqt [ it -> first ] -= 1 ;  // Decrementing the count in freqt
        }
    }

    // Counting whoops by transforming characters to match
    for ( it = freqs.begin ( ) ; it != freqs.end ( ) ; it++ ) {
        while ( it -> second > 0 ) {
            if ( it -> first >= 'a' and it -> first <= 'z' and freqt.find ( toupper ( it -> first ) ) != freqt.end ( ) and freqt [ toupper ( it -> first ) ] > 0 ) {
                whoops += 1 ;  // Incrementing whoops if transformation is possible
                it -> second -= 1 ;  // Decrementing the count in freqs
                freqt [ toupper ( it -> first ) ] -= 1 ;  // Decrementing the count in freqt
            }
            else if ( it -> first >= 'A' and it -> first <= 'Z' and freqt.find ( tolower ( it -> first ) ) != freqt.end ( ) and freqt [ tolower ( it -> first ) ] > 0 ) {
                whoops += 1 ;  // Incrementing whoops if transformation is possible
                it -> second -= 1 ;  // Decrementing the count in freqs
                freqt [ tolower ( it -> first ) ] -= 1 ;  // Decrementing the count in freqt
            }
            else {
                break ;  // Breaking the loop if no more transformations are possible
            }
        }
    }

    cout << yay << " " << whoops << endl ;  // Printing the final counts of yay and whoops

    return 0 ;
}

